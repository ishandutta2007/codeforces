
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)
#define int ll
const int maxn = 1e6+5;
const int mod = 1e9+7;
int a[maxn],b[maxn];
int bit[maxn];
int n;
void add(int a,int val)
{
    for(;a<=n;a+=a&-a)
    {
        bit[a]+=val;
        if(bit[a]>mod) bit[a]-=mod;
    }
}
ll sum(int x)
{
    ll ret=0;
    for(;x>0;x-=x&-x)
    {
        ret+=bit[x];
        if(ret>mod)ret-=mod;
    }
    return ret;
}
int32_t main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    rep(i,n) cin>>a[i];
    memcpy(b,a,sizeof(int)*(n+1));
    sort(b+1,b+1+n);
    ll ans = 0;
    rep(i,n)
    {
        ans += a[i] * i % mod * (n-i+1) % mod;
        if(ans>mod) ans-=mod;
    }
    for(int i=1;i<=n;++i)
    {
        int pos=lower_bound(b+1, b+1+n, a[i]) - b;
        add(pos,i);
        ans += a[i] * sum(pos-1) % mod * (n-i+1) % mod;
        if(ans>mod) ans-=mod;
    }
    memset(bit,0,sizeof(bit));
    for(int i=n;i>=1;--i)
    {
        int pos=lower_bound(b+1, b+1+n, a[i]) - b;
        add(pos,n-i+1);
        ans += a[i] * sum(pos-1) % mod * i % mod;
        if(ans>mod) ans-=mod;
    }
    cout<<ans<<endl;
}