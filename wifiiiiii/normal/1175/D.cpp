#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int i=1;i<=n;++i)

ll a[300005],suf[300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    for(int i=n;i>=1;--i) suf[i]=suf[i+1]+a[i];
    ll ans = suf[1];
    sort(suf+2,suf+1+n);
    for(int i=n,j=k-1;j;--i,--j) ans += suf[i];
    cout<<ans<<endl;
}