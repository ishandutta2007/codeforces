#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 1000000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vector<pii> e[maxn+5],se[maxn+5];
int dfn[maxn+5],cnt,low[maxn+5],sta[maxn+5],top,scc[maxn+5],tot;
void tarjan(int now)
{
    dfn[now]=low[now]=++cnt;
    sta[++top]=now;
    for(auto it: e[now])
    {
        int v=it.FI;
        if(!dfn[v])
        {
            tarjan(v);
            low[now]=min(low[now],low[v]);
        }
        else if(!scc[v]) low[now]=min(low[now],dfn[v]);
    }
    if(low[now]==dfn[now])
    {
        tot++;
        while(sta[top]!=now) scc[sta[top--]]=tot;
        scc[sta[top--]]=tot;
    }
}

ll dp[maxn+5];
int caltime(int n)
{
    int x=sqrt(n*2);
    while((x+1)*x/2<n) x++;
    while((x+1)*x/2>n) x--;
    return x;
}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,m)
    {
        int x,y,w; scanf("%d%d%d",&x,&y,&w);
        e[x].pb(mp(y,w));
    }
    rep(i,1,n) if(!dfn[i]) tarjan(i);
    rep(now,1,n) for(auto it: e[now])
    {
        int v=it.FI,w=it.SE;
        if(scc[now]==scc[v])
        {
            int t=caltime(w);
            dp[scc[now]]+=1ll*w*(t+1)-(1ll*t*(t+1)/2+1ll*t*(t+1)*(2*t+1)/6)/2;
        }
        else se[scc[now]].pb(mp(scc[v],w));
    }
    rep(i,1,tot)
    {
        ll tmp=0;
        for(auto it: se[i])
        {
            int v=it.FI,w=it.SE;
            int t=caltime(w);
            tmp=max(tmp,dp[v]+w);
        }
        dp[i]+=tmp;
    }
    int s; scanf("%d",&s);
    printf("%I64d\n",dp[scc[s]]);
    return 0;
}