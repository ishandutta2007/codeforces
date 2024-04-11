#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

inline void add(ll &x,ll y) {x+=y; if(x>=mod) x-=mod;}

int dp[maxn+5][2];
vi e[maxn+5];

void dfs(int now)
{
    ll tmp[2][2][2]={1,0,0,0,0,0,0,0};
    for(auto v: e[now])
    {
        dfs(v);
        ll tt[2][2][2]={};
        rep(o1,0,1) rep(i,0,1) rep(j,0,1) rep(o2,0,1) add(tt[o1^o2][i|(o2==0)][j|(o2==1)],tmp[o1][i][j]*dp[v][o2]%mod);
        rep(o,0,1) rep(i,0,1) rep(j,0,1) add(tmp[o][i][j],tt[o][i][j]);
    }
    dp[now][0]=(tmp[1][0][0]+tmp[1][0][1]+tmp[1][1][0]*2+tmp[1][1][1]*2)%mod;
    dp[now][1]=(tmp[0][0][0]+tmp[0][0][1]*2+tmp[0][1][0]+tmp[0][1][1]*2)%mod;
}

int main()
{
    int n; scanf("%d",&n);
    rep(i,2,n)
    {
        int x; scanf("%d",&x); e[x].pb(i);
    }
    dfs(1);
    printf("%d\n",(dp[1][0]+dp[1][1])%mod);
    return 0;
}