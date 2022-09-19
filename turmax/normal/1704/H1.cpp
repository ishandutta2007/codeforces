#pragma GCC optimize("O3","unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
#define int long long
static int p;
const int maxn=5e3+5;
int po(int a,int b) {if(b==0) return 1;if(b==1) return a;if(b%2==0) {int u=po(a,b/2);return (u*u)%p;} else {int u=po(a,b-1);return (a*u)%p;}}
int inv(int x) {return po(x,p-2);}
int fact[maxn];int invf[maxn];int dp[maxn][maxn];int po1[maxn];int lp[maxn];int pot[maxn][maxn];
int c(int n,int k)
{
    int ans=fact[n];ans*=invf[k];ans%=p;ans*=invf[n-k];ans%=p;return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n>>p;
    for(int i=0;i<maxn;++i) lp[i]=(-1);
    for(int i=2;i<maxn;++i) for(int j=2*i;j<maxn;j+=i) lp[j]=i;
    fact[0]=1;invf[0]=1;for(int i=1;i<maxn;++i) {fact[i]=(fact[i-1]*i)%p;invf[i]=inv(fact[i]);}
    int ans=0;
    for(int i=0;i<=n;++i)
    {
        for(int j=0;j<=n;++j)
        {
            if(lp[i]==(-1))
            {
                pot[i][j]=po(i,j);
            }
            else
            {
                pot[i][j]=(pot[lp[i]][j]*pot[i/lp[i]][j])%p;
            }
        }
    }
    for(int c=0;c<=n;++c)
    {
        for(int a=0;a<=n;++a)
        {
            if(c==0)
            {
                dp[c][a]=1;continue;
            }
            if(a==0)
            {
                dp[c][a]=0;continue;
            }
            dp[c][a]=(c-1)*dp[c-1][a]+a*dp[c-1][a];dp[c][a]%=p; //dp(c,a)=(a+c-1)*...*a ???
        }
    }
    for(int i=0;i<=n;++i) po1[i]=po(n-1,i);
    for(int a=0;a<=n;++a)
    {
        for(int b=0;b<=n;++b)
        {
            int c=n-2*a-b;
            if(c<0) continue;
            int d=a;
            int u=fact[n];u*=invf[b];u%=p;u*=invf[c];u%=p;u*=invf[d];u%=p;
            u*=dp[c][a];u%=p;
            u*=po1[d];u%=p;u*=pot[n-a-b][b];u%=p;
            ans+=u;if(ans>=p) ans-=p;
        }
    }
    cout<<(ans%p+p)%p;
    return 0;
}