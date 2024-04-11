#include <bits/stdc++.h>
#define fi first
#define se second
#define mid (l+r>>1)
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
const int N=2e6+10;
const int inf=0x3f3f3f3f;
const int mod=998244353;
ll m,x;
set<ll>s;
vector<ll>u,v;
ll mm(ll a,ll b,ll c)
{
    ll ret=0;
    for(;b;b>>=1,a=a*2%c)
        if(b&1)ret=(ret+a)%c;
    return ret;
}
ll qm(ll a,ll b,ll c)
{
    ll ret=1;
    for(a%=c;b;b>>=1,a=mm(a,a,c))
        if(b&1)ret=mm(ret,a,c);
    return ret;
}
ll ou(ll a)
{
    ll b=a,t=a;
    for(ll i=2;i*i<=t;i++)
    {
        if(t%i==0)
        {
            b=b/i*(i-1);
            while(t%i==0)t/=i;
        }
    }
    if(t!=1)b=b/t*(t-1);
    return b;
}
ll f(ll a)
{
    ll b=ou(a);
    for(int i=0;i<u.size();i++)if(b%u[i]==0)
    {
        if(v[i]%a<=1)return b/u[i];
    }
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("1.txt","r",stdin);
    cin>>m>>x;
    for(ll i=1;i*i<=m;i++)if(m%i==0)
    {
        s.insert(i);
        s.insert(m/i);
    }
//    cout<<s.size()<<endl;
    for(ll a=ou(m),i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            u.push_back(i);
            u.push_back(a/i);
        }
    }
    sort(u.begin(),u.end());
    unique(u.begin(),u.end());
    v.resize(u.size());
    for(int i=0;i<u.size();i++)
    {
        v[i]=qm(x,u[i],m);
    }

    ll ans=0;
    for(auto i:s)
    {
//        cout<<i<<' '<<f(i)<<endl;
        ans+=f(i);
    }
    cout<<ans;
    return 0;
}