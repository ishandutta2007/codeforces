#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 300000
#define mod 998244353
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int l[maxn+5],r[maxn+5],cnt[maxn+5];
int a[21],b[21];

ll fac[maxn+5],ifac[maxn+5],inv[maxn+5];
int ways[41][maxn+5];

ll binom(int n,int m)
{
    if(m<0 || n<m) return 0;
    return fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}

int chosen[maxn+5],tot;
ll ans;

void solve(int m,int n,int L,int R,int C)
{
    if(L>R) return;
    if(m==0)
    {
        ll tmp=(ways[tot][R]-ways[tot][L-1]+mod)%mod;
        if(C==0) ans=(ans+tmp)%mod;
        else ans=(ans-tmp+mod)%mod;
        return;
    }
    solve(m-1,n,L,R,C);
    if(chosen[a[m]]++==0) tot++;
    if(chosen[b[m]]++==0) tot++;
    solve(m-1,n,max(L,max(l[a[m]],l[b[m]])),min(R,min(r[a[m]],r[b[m]])),C^1);
    if(--chosen[a[m]]==0) tot--;
    if(--chosen[b[m]]==0) tot--;
}

int main()
{
    fac[0]=ifac[0]=inv[1]=1;
    rep(i,2,maxn) inv[i]=inv[mod%i]*(mod-mod/i)%mod;
    rep(i,1,maxn) fac[i]=fac[i-1]*i%mod;
    rep(i,1,maxn) ifac[i]=ifac[i-1]*inv[i]%mod;

    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) scanf("%d%d",&l[i],&r[i]);
    rep(i,1,m) scanf("%d%d",&a[i],&b[i]);
    rep(i,1,n) cnt[l[i]]++,cnt[r[i]+1]--;
    rep(i,1,n) cnt[i]+=cnt[i-1];
    rep(sub,0,m*2) rep(i,1,n) ways[sub][i]=binom(cnt[i]-sub,i-sub);
    rep(sub,0,m*2) rep(i,1,n) ways[sub][i]=(ways[sub][i]+ways[sub][i-1])%mod;
    
    solve(m,n,1,n,0);
    printf("%lld\n",ans);
    return 0;
}