#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i %i",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    long long p[n],s=0;
    for(int i=0;i<n;i++){
        if(i==0)p[i]=a[i];
        else p[i]=p[i-1]+a[i];
    }
    for(int i=k-1;i<n;i++)s+=p[i]-(i==k-1?0:p[i-k]);
    printf("%.6lf",(double)s/(double)(n-k+1));
}