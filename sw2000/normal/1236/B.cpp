#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

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

int main()
{
    //freopen("in.txt","r",stdin);
    ll n,m;
    cin>>n>>m;
    ll ans=pm(2,m,mod)-1;
    ans=pm(ans,n,mod);
    cout<<ans<<endl;
    return 0;
}