#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'
struct Dinic
{
    static const int maxn = 4000005;
    static const int maxm = 8000005;
    struct edge
    {
        int to,next,cap,flow;
    }es[maxm];
    int d[maxn],cur[maxn],s,t,n;
    int head[maxn],tol;
    queue<int> q;
    void init() {memset(head,-1,sizeof(head));tol=0;}
    inline void adde(int u,int v,int w)
    {
        es[tol] = {v,head[u],w,0}; head[u] = tol++;
        es[tol] = {u,head[v],0,0}; head[v] = tol++;
    }
    bool bfs()
    {
        for(int i=0;i<=n;++i) d[i]=-1;
        d[s]=0;
        q.push(s);
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i=head[u];i!=-1;i=es[i].next)
            {
                int v = es[i].to;
                if(d[v]==-1 && es[i].cap>es[i].flow)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t]!=-1;
    }
    int dfs(int u,int low)
    {
        if(u==t || !low) return low;
        int f = 0;
        for(int &i=cur[u];i!=-1;i=es[i].next)
        {
            int v = es[i].to, tmp = 0;
            if(d[u]+1 == d[v] && (tmp=dfs(v,min(low,es[i].cap-es[i].flow))))
            {
                es[i].flow += tmp;
                es[i^1].flow -= tmp;
                f += tmp;
                low -= tmp;
                if(!low) break;
            }
        }
        return f;
    }
    int Maxflow(int s,int t,int n)
    {
        this->s = s, this->t = t, this->n = n;
        int ans = 0;
        while(bfs())
        {
            for(int i=0;i<n;++i) cur[i]=head[i];
            ans += dfs(s,1e9);
        }
        return ans;
    }
};
int n,m;
inline int hsh(int x,int y)
{
    return m*(x-1)+y;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    vector<vector<char>> g(n+1,vector<char>(m+1));
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            cin>>g[i][j];
    Dinic dinic;
    dinic.init();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
        {
            if(g[i][j] == '#') continue;
            if(i==1 && j==1) dinic.adde(1,1+n*m,2);
            else if(i==n && j==m) dinic.adde(hsh(i,j),hsh(i,j)+n*m,2);
            else dinic.adde(hsh(i,j),hsh(i,j)+n*m,1);
            if(i+1<=n && g[i+1][j]=='.') dinic.adde(hsh(i,j)+n*m,hsh(i+1,j),1);
            if(j+1<=m && g[i][j+1]=='.') dinic.adde(hsh(i,j)+n*m,hsh(i,j+1),1);
        }
    int mf = dinic.Maxflow(1,hsh(n,m)+n*m,hsh(n,m)+n*m);
    cout<<mf<<endl;
}