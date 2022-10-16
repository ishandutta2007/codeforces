#include "bits/stdc++.h"
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 20
#define mod 1000000007
#define inf 0x3f3f3f3f
template<class T> bool chmax(T &a, const T &b) {if(a<b) {a=b; return 1;} return 0;}
template<class T> bool chmin(T &a, const T &b) {if(b<a) {a=b; return 1;} return 0;}
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int deg[maxn+5],coef[maxn+5];
int dp[1<<18],pre[18][1<<18],msk[maxn+5];

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w); x--; y--;
        e[x].pb(y);
        deg[y]++;
        coef[x]+=w; coef[y]-=w;
        msk[x]|=1<<y;
    }
    vi ver;
    queue<int> q;
    rep(i,0,n-1) if(deg[i]==0) q.push(i);
    while(q.size())
    {
        int now=q.front(); q.pop();
        ver.pb(now);
        for(auto v: e[now]) if(--deg[v]==0) q.push(v);
    }
    memset(dp,0x3f,sizeof dp);
    dp[0]=0;
    int N=1<<n;
    rep(i,0,n-1) 
    {
        for(auto now: ver) rep(s,0,N-1) if(s&(1<<now) && (s&msk[now])==msk[now] && dp[s^(1<<now)]!=inf) if(chmin(dp[s],dp[s^(1<<now)]+i*coef[now])) pre[i][s]=pre[i][s^(1<<now)] | (1<<now);
        //rep(s,0,N-1) printf("? %d: %d - %d, %d\n",i,s,dp[s],pre[i][s]);
    }
    vi ans(n,0);
    for(int i=n-1,s=N-1;s;s=s^pre[i][s],i--) 
    {
        //printf("? %d %d\n",i,s);
        rep(j,0,n-1) if(pre[i][s]&(1<<j)) ans[j]=i;
    }
    rep(i,0,n-1) printf("%d%c",ans[i]," \n"[i==n-1]);
    return 0;
}