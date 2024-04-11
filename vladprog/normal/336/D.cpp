#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=2e5+100;
const int MOD=1e9+7;

int f[N+1];

void precalc()
{
    f[0]=1;
    for(int i=1;i<=N;i++)
        f[i]=f[i-1]*i%MOD;
}

int ppow(int x,int y)
{
    if(y==0)
        return 1;
    if(y==1)
        return x;
    int p=ppow(x,y/2);
    return p*p%MOD*ppow(x,y%2)%MOD;
}

int c(int n,int k)
{
    if(k>n||n<0)
        return 0;
    return f[n]*ppow(f[k],MOD-2)%MOD*ppow(f[n-k],MOD-2)%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precalc();
    int n,m,g;
    cin>>n>>m>>g;
    if(m==0)
        cout<<((n&1)!=g),exit(0);
    int ans=(m==1&&((n&1)!=g));
    for(int i=0;i<=n;i++)
        if((i&1)==g&&!(m==1&&i==n))
            ans=(ans+c(n+m-i-1,m-1))%MOD;
    cout<<ans;
}