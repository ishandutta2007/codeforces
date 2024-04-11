#include <bits/stdc++.h>
using namespace std;
void Solve(double n){
    if(n==0){
        printf("Y %.9lf %.9lf\n",0.0,0.0);
        return;
    }
    if(n<4){
        printf("N\n");
        return;
    }
    double D=sqrt(n*n-n*4);
    double A=(n+D)/2,B=(n-D)/2;
    printf("Y %.9lf %.9lf\n",A,B);
}
int main(){
    int T;
    scanf("%i",&T);
    while(T--){
        double d;
        scanf("%lf",&d);
        Solve(d);
    }
    return 0;
}