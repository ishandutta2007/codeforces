#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 2000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

int g[maxn+5][maxn+5];
ll dis[maxn+5];
bool mark[maxn+5];

int main()
{
    int n; scanf("%d",&n);
    int mn=inf;
    rep(i,1,n) rep(j,i+1,n) scanf("%d",&g[i][j]),mn=min(mn,g[i][j]);
    rep(i,1,n) rep(j,i+1,n) g[j][i]=(g[i][j]-=mn);

    rep(i,0,n) dis[i]=1ll<<60;
    rep(i,1,n) rep(j,1,n) if(i!=j) dis[i]=min(dis[i],2ll*g[i][j]);
    
    rep(i,1,n)
    {
        int now=0;
        rep(j,1,n) if(mark[j]==0 && dis[j]<dis[now]) now=j;
        mark[now]=1;
        rep(v,1,n) if(v!=now && dis[v]>dis[now]+g[now][v]) dis[v]=dis[now]+g[now][v]; 
    }
    rep(i,1,n) printf("%lld\n",dis[i]+1ll*(n-1)*mn);
    return 0;
}