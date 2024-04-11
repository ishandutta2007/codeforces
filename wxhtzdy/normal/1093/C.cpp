#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;scanf("%i",&n);
    long long a[n/2],b[n];
    for(int i=0;i<n/2;i++)scanf("%lld",&a[i]);
    b[0]=0,b[n-1]=a[0];
    long long lst=b[n-1];
    for(int i=1;i<n/2;i++){
        long long x=b[i-1],y=b[n-i];
        b[n-i-1]=lst;
        assert(a[i]<=y*2);
        if(a[i]-y>=x){
            b[i]=a[i]-y;
            b[n-i-1]=y;
        }else{
            b[i]=x;
            b[n-i-1]=a[i]-x;
        }
    }
    for(int i=0;i<n;i++)printf("%lld ",b[i]);
    return 0;
}