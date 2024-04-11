#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    scanf("%i%i",&n,&k);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    double mx=2*max(a[0],k-a[n-1]);
    for(int i=1;i<n;i++)mx=max(mx,(double)(a[i]-a[i-1]));
    printf("%.10f",mx/2.0);
}