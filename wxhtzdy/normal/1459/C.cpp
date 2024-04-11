#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m;scanf("%i %i",&n,&m);
    ll a[n],b[m];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    for(int i=0;i<m;i++)scanf("%lld",&b[i]);
    sort(a,a+n);
    ll g=0;
    for(int i=1;i<n;i++)g=__gcd(g,abs(a[i]-a[i-1]));
    for(int i=0;i<m;i++){
        printf("%lld ",__gcd(a[0]+b[i],g));
    }
    return 0;
}