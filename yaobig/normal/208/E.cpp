#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

vi e[maxn+5];
vi H[maxn+5];
int in[maxn+5],out[maxn+5],dfn;
int anc[maxn+5][18],dep[maxn+5];
void dfs(int now)
{
    in[now]=++dfn;
    H[dep[now]].pb(dfn);
    for(auto v: e[now])
    {
        anc[v][0]=now;
        dep[v]=dep[now]+1;
        dfs(v);
    }
    out[now]=dfn;
}
int swim(int x,int h)
{
    for(int i=0;h;i++,h>>=1) if(h&1) x=anc[x][i];
    return x;
}
int main()
{
    int n; scanf("%d",&n);
    rep(i,1,n)
    {
        int x; scanf("%d",&x);
        e[x].pb(i);
    }
    dfs(0);
    rep(i,1,16) rep(j,1,n) anc[j][i]=anc[anc[j][i-1]][i-1];

    int m; scanf("%d",&m);
    rep(i,1,m)
    {
        int v,h; scanf("%d%d",&v,&h);
        int p=swim(v,h);
        if(!p) printf("%d%c",0," \n"[i==m]);
        else
        {
            int l=lower_bound(H[dep[v]].begin(),H[dep[v]].end(),in[p])-H[dep[v]].begin();
            int r=upper_bound(H[dep[v]].begin(),H[dep[v]].end(),out[p])-H[dep[v]].begin()-1;
            printf("%d%c",r-l," \n"[i==m]);
        }
    }
    return 0;
}