#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    scanf("%i%i",&n,&m);
    long long a[m];
    for(int i=0;i<m;i++)scanf("%lld",&a[i]);
    long long cnt=(long long)0;
    for(int i=1;i<m;i++)if(a[i]<a[i-1])cnt++;
    printf("%lld",cnt*n-1+a[m-1]);
}