#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

const int mod = 998244353;
ll a[200005],b[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    rep(i,n) cin>>a[i];
    ll l=1,r=n;
    rep(i,n)
    {
        a[i]=a[i]*l*r;
        l++,r--;
    }
    sort(a+1,a+1+n);
    rep(i,n) a[i]%=mod;
    rep(i,n) cin>>b[i];
    sort(b+1,b+1+n);
    reverse(b+1,b+1+n);
    ll ans = 0;
    rep(i,n) (ans+=a[i]*b[i]%mod)%=mod;
    cout<<ans<<endl;
}