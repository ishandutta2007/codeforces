
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)

const int mod = 998244353;
int w0,w1,a0,a1;
int a[200005],b[200005];
int dp[3005][3005];
int fpow(int a,int b)
{
    int ret = 1;
    while(b)
    {
        if(b&1) ret=1ll*ret*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    if(ret<0) ret+=mod;
    return ret;
}
int ans[200005];
inline int read()
{
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}
int main()
{
    int w1=0,w0=0,a0=0,a1=0;
    int n=read(),m=read();
    rep(i,n) a[i]=read();
    rep(i,n) b[i]=read();
    rep(i,n) if(a[i]) w1+=b[i];else w0+=b[i];
    int fw1=fpow(w1,mod-2),fw0=fpow(w0,mod-2);
    dp[0][0] = 1;
    for(int i=0;i<=m;++i)
    {
        for(int j=0;j<=m;++j)
        {
            if(i+j>m) continue;
            dp[i][j] += 1ll * (w1+i-1) * fpow(w0+w1+i-1-j, mod-2) % mod * dp[i-1][j] % mod;
            dp[i][j] += 1ll * (w0-j+1) * fpow(w0+w1+i-j+1, mod-2) % mod * dp[i][j-1] % mod;
            while(dp[i][j] > mod) dp[i][j] -= mod;
        }
    }
    for(int i=0;i<=m;++i)
    {
        a0 += 1ll * (m-i) * dp[i][m-i] % mod;
        a1 += 1ll * i * dp[i][m-i] % mod;
        if(a0 > mod) a0 -= mod;
        if(a1 > mod) a1 -= mod;
    }
    rep(i,n)
    {
        if(a[i]) ans[i] = b[i] + 1ll * a1 * b[i] % mod * fw1 % mod;
        else ans[i] = b[i] - 1ll * a0 * b[i] % mod * fw0 % mod;
        while(ans[i] > mod) ans[i] -= mod;
        if(ans[i]<0) ans[i]+=mod;
        printf("%d\n",ans[i]);
    }
}