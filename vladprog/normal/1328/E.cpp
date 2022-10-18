#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=2e5+100;

vector<int> g[N];
int tin[N],tout[N],h[N],timer=1,par[N];

void dfs(int v,int cur,int p)
{
    par[v]=p;
    h[v]=cur;
    tin[v]=timer++;
    for(int to:g[v])
        if(to!=p)
            dfs(to,cur+1,v);
    tout[v]=timer++;
}

int v[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,1);
    while(m--)
    {
        int k;
        cin>>k;
        pii p(-1,-1);
        for(int i=1;i<=k;i++)
            cin>>v[i],
            v[i]=par[v[i]],
            p=max(p,pii(h[v[i]],v[i]));
        int u=p.y;
        bool ok=true;
        for(int i=1;i<=k;i++)
            if(!(tin[v[i]]<=tin[u]&&tout[u]<=tout[v[i]]))
                ok=false;
        cout<<(ok?"YES\n":"NO\n");
    }
}