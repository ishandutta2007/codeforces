#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define N 1000010
#define ll long long
#define mod 998244353
int n;
ll f[N],g[N],ans,inv[N];
inline ll q_pow(ll x,int n){ll ret=1;for(;n;n>>=1,x=x*x%mod)if(n&1)ret=ret*x%mod;return ret;}
int main()
{
    scanf("%d",&n);
    f[0]=1ll;
    for(int i=1;i<=n;i++)
        f[i]=(f[i-1]*i)%mod,inv[i]=q_pow(f[i],mod-2);
    for(int i=1;i<=n;i++)g[i]=(f[n]*inv[n-i])%mod;
    (ans+=f[n])%=mod;
    for(int i=2;i<n;i++)(ans+=(g[n-i]*(f[i]-1+mod))%mod)%=mod;
    printf("%lld\n",ans);
    return 0;
}