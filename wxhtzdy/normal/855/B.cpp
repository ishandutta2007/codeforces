#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int n;
ll p,q,r,a[N];
int main(){
    scanf("%i %lld %lld %lld",&n,&p,&q,&r);
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    ll pref[n],suff[n];
    for(int i=0;i<n;i++){
        if(i==0)pref[i]=a[i]*p;
        else pref[i]=max(pref[i-1],a[i]*p);
    }
    for(int i=n-1;i>=0;i--){
        if(i==n-1)suff[i]=a[i]*r;
        else suff[i]=max(suff[i+1],a[i]*r);
    }
    ll ans=-3e18;
    for(int i=0;i<n;i++)ans=max(ans,pref[i]+a[i]*q+suff[i]);
    printf("%lld",ans);
    return 0;
}