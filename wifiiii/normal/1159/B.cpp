#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=1;i<=n;++i)

inline ll read()
{
    char c=getchar();ll x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
ll a[300005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n=read();
    rep(i,n) a[i]=read();
    ll lo = 0, hi = 1e9;
    while(lo<hi)
    {
        ll m = (lo+hi+1)/2;
        int ok = 1;
        for(ll i=1;i<=n;++i)
        {
            if((i-1)*m>min(a[i],a[1])) ok=0;
            if((n-i)*m>min(a[i],a[n])) ok=0;
        }
        if(ok) lo=m;
        else hi=m-1;
    }
    cout<<lo<<endl;
}