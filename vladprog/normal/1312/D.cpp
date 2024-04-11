#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int MOD=998244353;

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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    if(n==2)
        cout<<0,exit(0);
    int ans=1;
    for(int i=1;i<=m;i++)
        ans=ans*i%MOD;
    for(int i=1;i<=n-1;i++)
        ans=ans*ppow(i,MOD-2)%MOD;
    for(int i=1;i<=m-n+1;i++)
        ans=ans*ppow(i,MOD-2)%MOD;
    ans=ans*(n-2)%MOD;
    for(int i=1;i<=n-3;i++)
        ans=ans*2%MOD;
    cout<<ans;
}