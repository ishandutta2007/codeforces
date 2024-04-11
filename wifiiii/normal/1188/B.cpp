#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define int ll
const int maxn = 300005;
ll a[maxn],b[maxn];
map<ll,int> mp;
ll fpow(ll a,ll b,ll mod)
{
    ll ret = 1;
    while(b)
    {
        if(b&1) ret=ret*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ret;
}
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n,p,k;
    cin>>n>>p>>k;
    forii cin>>a[i];
    forii b[i]=fpow(a[i],4,p);
    ll ans = 0;
    forii
    {
        ll tmp = b[i]-a[i]*k;
        tmp%=p;
        if(tmp<0) tmp+=p;
        ans+=mp[tmp];
        mp[tmp]++;
    }
    cout<<ans<<endl;
}