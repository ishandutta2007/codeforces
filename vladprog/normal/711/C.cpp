#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N=110,INF=1e18;

///  [n][k][c]       [n][c]
ll dp[N][N][N],c[N],p[N][N],m;

ll calc(ll n,ll k,ll t)
{
    if(n<=0)
        return (k==0)?0:INF;
    if(k<=0)
        return INF;
    if(c[n]!=0&&c[n]!=t)
        return INF;
    if(n==1&&k!=1)
        return INF;
    ll &res=dp[n][k][t];
    if(n>1)
    {
        if(res>=0)
            return res;
        res=INF;
        for(int i=1;i<=m;i++)
            res=min(res,calc(n-1,k-(t!=i),i));
    }
    else
        res=0;
    if(!c[n])
        res+=p[n][t];
    return res;
}

int main()
{
    ll n,k;
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)
        cin>>c[i];
    for(ll i=1;i<=n;i++)
        for(ll j=1;j<=m;j++)
            cin>>p[i][j];
    ll ans=INF;
    memset(dp,255,sizeof(dp));
    for(ll i=1;i<=m;i++)
        ans=min(ans,calc(n,k,i));
    if(ans>=INF)
        ans=-1;
    cout<<ans;
}