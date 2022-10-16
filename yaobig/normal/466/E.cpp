#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf (1ll<<60)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int fa[maxn+5];
int getfa(int x)
{
    if(x==fa[x]) return x;
    return fa[x]=getfa(fa[x]);
}

vi e[maxn+5];
int op[maxn+5][3];
int ans[maxn+5];
bool hasfa[maxn+5];

int in[maxn+5],out[maxn+5],dfn;

void dfs(int now)
{
    in[now]=++dfn;
    for(auto v: e[now]) dfs(v);
    out[now]=dfn;
}
vector<pii> q[maxn+5];

bool isson(int x,int y) {return in[y]>=in[x] && in[y]<=out[x];}

int main()
{
    int n,m; scanf("%d%d",&n,&m);
    rep(i,1,n) fa[i]=i;
    int cnt=0;
    rep(i,1,m)
    {
        scanf("%d",&op[i][0]);
        if(op[i][0]==1)
        {
            int x,y; scanf("%d%d",&x,&y);
            op[i][1]=x;
            op[i][2]=y;
            e[y].pb(x);
            hasfa[x]=1;
        }
        if(op[i][0]==2)
        {
            scanf("%d",&op[i][1]);
            op[i][2]=++cnt;
        }
        if(op[i][0]==3)
        {
            int x,y; scanf("%d%d",&x,&y);
            op[i][1]=x;
            op[i][2]=y;
            q[y].pb(mp(x,i));
        }
    }
    rep(i,1,n) if(hasfa[i]==0) e[0].pb(i);
    dfs(0);
    rep(i,1,m)
    {
        if(op[i][0]==1)
        {
            int x=op[i][1];
            int y=op[i][2];
            fa[getfa(x)]=getfa(y);
        }
        if(op[i][0]==2)
        {
            int x=op[i][1];
            int id=op[i][2];
            int anc=getfa(x);
            for(auto it: q[id])
            {
                int y=it.FI,qid=it.SE;
                ans[qid]=isson(anc,y) && isson(y,x);
            }
        }
        if(op[i][0]==3) printf("%s\n",ans[i]?"YES":"NO");
    }

    return 0;
}