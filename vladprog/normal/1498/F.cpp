#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

const int N=1e5+100,K=20;
typedef array<int,2*K> node;
int k;
void upd(node&u,const node&v)
{
    for(int i=0;i<2*k;i++)
        u[(i+1)%(2*k)]^=v[i];
}

vector<int> g[N];
int a[N];
node dp[N];
bool ans[N];

void upd(int u,int v)
{
    upd(dp[u],dp[v]);
}

void dfs1(int v,int p)
{
    dp[v][0]=a[v];
    for(int to:g[v])
        if(to!=p)
            dfs1(to,v),
            upd(v,to);
//    cout<<v<<" -> ";
//    for(int i=0;i<2*k;i++)
//        cout<<dp[v][i]<<" ";
//    cout<<"\n";
}

void dfs2(int v,int p)
{
    int cur=0;
    for(int i=k;i<2*k;i++)
        cur^=dp[v][i];
    ans[v]=cur;
    for(int to:g[v])
        if(to!=p)
        {
            upd(v,to);
            upd(to,v);
            dfs2(to,v);
            upd(to,v);
            upd(v,to);
        }
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n>>k;
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs1(1,-1);
    dfs2(1,-1);
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
}