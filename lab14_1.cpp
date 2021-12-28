#include <iostream>
#include <cmath>
using namespace std;

void stat(const double[],int,double[]);

int main(){
    double A[] = {1.2,3.5,6.9,7.8,12.5,0.5};
    int N = sizeof(A)/sizeof(A[0]);
    double B[6];
    stat(A,N,B);
    cout << "Arithmetic Mean = " << B[0];
    cout << "\nStandard Deviation = " << B[1];
    cout << "\nGeometric Mean = " << B[2];
    cout << "\nHarmonic Mean = " << B[3];
    cout << "\nMax = " << B[4];
    cout << "\nMin = " << B[5];
    return 0;
}


void stat(const double A[],int N, double B[]){
    double sum=0;
    double std=0;
    double geoM=1;
    double HM=0;
    double Max=A[0];
    double Min=A[0];
    for(int i=0;i<N;i++){
        
        sum = sum + A[i];
        std += pow(A[i],2);
        geoM = geoM*A[i];
        HM = HM+(1/A[i]);
        if(A[i] > Max) Max = A[i];
        if(A[i] < Min) Min = A[i];
    } 
    B[0] = sum/N;
    B[1] = sqrt((std/N)-pow(B[0],2));
    B[2] = pow(geoM,pow(N,-1));
    B[3] = N/HM;
    B[4] = Max;
    B[5] = Min;
}