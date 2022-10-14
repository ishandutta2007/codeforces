#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n,m,k;scanf("%i %i %i",&n,&m,&k);
    int a[n];
    for(int i=0;i<n;i++)scanf("%i",&a[i]);
    sort(a,a+n);
    reverse(a,a+n);
    ll cnt=m/(k+1);
    ll ans=(ll)a[0]*m-(ll)a[0]*cnt+a[1]*cnt;
    printf("%lld",ans);
    return 0;
}