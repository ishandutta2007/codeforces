#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N=4010;
const int MOD=1e9+7;

int b[N+1],f[N+1],r[N+1];

int ppow(int x,int y)
{
    int ans=1;
    while(y)
    {
        if(y&1)
            ans=ans*x%MOD;
        x=x*x%MOD;
        y>>=1;
    }
    return ans;
}

int c(int n,int k)
{
    return f[n]*r[k]%MOD*r[n-k]%MOD;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    f[0]=1;
    for(int i=1;i<=N;i++)
        f[i]=f[i-1]*i%MOD;

    r[N]=ppow(f[N],MOD-2);
    for(int i=N-1;i>=0;i--)
        r[i]=r[i+1]*(i+1)%MOD;

    b[0]=1;
    for(int n=0;n+1<=N;n++)
        for(int k=0;k<=n;k++)
            b[n+1]=(b[n+1]+c(n,k)*b[k])%MOD;

    int n;
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=(ans+c(n,i)*b[n-i]%MOD)%MOD;
    cout<<ans;
}