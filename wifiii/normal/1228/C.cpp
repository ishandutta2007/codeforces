#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 100005;
int prime[maxn],np[maxn],tot=0;
void init()
{
    np[1]=1;
    for(int i=2;i<maxn;++i)
    {
        if(!np[i]) prime[++tot] = i;
        for(int j=1;j<=tot;++j)
        {
            if(i*prime[j]>=maxn) break;
            np[i*prime[j]] = 1;
            if(i%prime[j]==0) break;
        }
    }
}
const int mod = 1e9+7;
ll fpow(ll a,ll b)
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
ll g(ll x,ll y)
{
    ll ret=1;
    while(x%y==0) x/=y,ret=ret*y%mod;
    return ret;
}
int main()
{
    
    init();
    ll n,k;
    cin>>n>>k;
    vector<ll> ps;
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            while(n%i==0) n/=i;
            if(!np[i]) ps.push_back(i);
        }
    }
    if(n>1) ps.push_back(n);
    ll ans = 1;
    for(int i=0;i<ps.size();++i)
    {
        ll cnt = 0;
        ll tmp = ps[i];
        while(1)
        {
            cnt += k / tmp;
            if(tmp > k / ps[i] + 1) break;
            tmp *= ps[i];
        }
        if(cnt) ans = ans * fpow(ps[i], cnt) % mod;
        ans %= mod;
    }
    cout << ans << endl;
}