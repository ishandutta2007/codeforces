#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=3e5+100;

int c[N];
vector<int> g[N];
int sub[N],near[N],ok[N];
bool ans[N];

void dfs1(int v,int p)
{
    sub[v]=near[v]=c[v];
    ok[v]=0;
    for(int to:g[v])
        if(to!=p)
            dfs1(to,v),
            sub[v]+=sub[to],
            near[v]+=c[to],
            ok[v]+=ok[to];
    ok[v]+=near[v]&&sub[v]>=2;
}

void dfs2(int v,int p)
{
    ans[v]=ok[v];
    for(int to:g[v])
        if(to!=p)
        {
            ok[v]-=near[v]&&sub[v]>=2;
            sub[v]-=sub[to];
            near[v]-=c[to];
            ok[v]-=ok[to];
            ok[v]+=near[v]&&sub[v]>=2;

            ok[to]-=near[to]&&sub[to]>=2;
            sub[to]+=sub[v];
            near[to]+=c[v];
            ok[to]+=ok[v];
            ok[to]+=near[to]&&sub[to]>=2;

            dfs2(to,v);

            ok[to]-=near[to]&&sub[to]>=2;
            sub[to]-=sub[v];
            near[to]-=c[v];
            ok[to]-=ok[v];
            ok[to]+=near[to]&&sub[to]>=2;

            ok[v]-=near[v]&&sub[v]>=2;
            sub[v]+=sub[to];
            near[v]+=c[to];
            ok[v]+=ok[to];
            ok[v]+=near[v]&&sub[v]>=2;
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(1,0);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}