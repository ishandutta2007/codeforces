#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1500
#define mod 998244353
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int a[maxn+5][maxn+5];
int fa[maxn+5],sz[maxn+5],cnt[maxn+5],dp[maxn+5][maxn+5];
int x[maxn*maxn+5],y[maxn*maxn+5];

int getfa(int x) {return x==fa[x]?x:fa[x]=getfa(fa[x]);}

int main()
{
    int n,m; scanf("%d",&n); m=n*(n-1)/2;
    rep(i,1,n) rep(j,1,n)
    {
        int w; scanf("%d",&w);
        if(i<j) x[w]=i,y[w]=j;
    }
    rep(i,1,n) fa[i]=i,sz[i]=1,dp[i][1]=1;
    rep(id,1,m)
    {
        int fx=getfa(x[id]),fy=getfa(y[id]);
        if(fx!=fy)
        {
            if(sz[fx]<sz[fy]) swap(fx,fy);
            fa[fy]=fx;
            vi tmp(sz[fx]+sz[fy]+1,0);
            rep(i,1,sz[fx]) rep(j,1,sz[fy]) tmp[i+j]=(tmp[i+j]+1ll*dp[fx][i]*dp[fy][j])%mod;
            sz[fx]+=sz[fy];
            cnt[fx]+=cnt[fy];
            rep(i,1,sz[fx]) dp[fx][i]=tmp[i];
        }
        if(++cnt[fx]==sz[fx]*(sz[fx]-1)/2) dp[fx][1]=(dp[fx][1]+1)%mod;
    }
    rep(i,1,n) printf("%d%c",dp[getfa(1)][i]," \n"[i==n]);
    return 0;
}