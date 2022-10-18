#include <bits/stdc++.h>

typedef long long ll;
#define int ll

using namespace std;

const int MOD=1e9+7,INF=2e18;

int mult(int x,int y)
{
    if(INF/x/y)
        return x*y;
    else
        return INF;
}

int ppow(int x,int y)
{
    int res=1;
    while(y)
    {
        if(y&1)
            res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}

int solve(int n,int p)
{
    int res=0;
    for(int k=1,pw=p;pw<=n;k++,pw=mult(pw,p))
        res+=n/pw;
    return ppow(p%MOD,res);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x,n;
    cin>>x>>n;
    int ans=1;
    for(int p=2;p*p<=x;p++)
    {
        if(x%p==0)
            ans=ans*solve(n,p)%MOD;
        while(x%p==0)
            x/=p;
    }
    if(x>1)
        ans=ans*solve(n,x)%MOD;
    cout<<ans;
}