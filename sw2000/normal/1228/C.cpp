#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e3+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const ll linf=0x3f3f3f3f3f3f3f3f;

inline ll mm(ll a,ll n,ll m)
{
    ll ret=0;
    for(; n; n>>=1,a=a*2%m)
        if(n&1)
            ret=(ret+a)%m;
    return ret;
}

inline ll pm(ll a,ll n,ll m)
{
    ll ret=1;
    for(; n; n>>=1,a=mm(a,a,m))
        if(n&1)
            ret=mm(ret,a,m);
    return ret;
}

vector<ll>v;

int main()
{
    ll x,n,ans=1;
    cin>>x>>n;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            v.push_back(i);
            while(x%i==0)x/=i;
        }
    }
    if(x!=1)v.push_back(x);
    for(int i=0;i<v.size();i++)
    {
        ll a=v[i];
        ll b=n/a;
        ll sum=0;
        while(b)
        {
            sum+=b;
            b/=a;
        }
        ans=mm(ans,pm(a,sum,mod),mod);
    }
    cout<<ans;
    return 0;
}