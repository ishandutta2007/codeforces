#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define endl '\n'
using namespace std;
typedef long long ll;
typedef vector<int>vi;
typedef pair<int, int>pii;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;

int n,m,d[N],dd[N],vis[N];
vi edg[N];
void dfs(int u=1)
{
    for(auto v:edg[u])
    {
        if(d[v]>d[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dfs(v);
            }
            dd[u]=min(dd[u],dd[v]);
        }
        else
        {
            dd[u]=min(dd[u],d[v]);
        }
    }
}
void solve()
{
    cin>>n>>m;
    for(int i=2; i<=n; i++)
    {
        d[i]=-1;
        vis[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        edg[a].push_back(b);
    }
    queue<int>q;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:edg[u])
        {
            if(d[v]==-1)
            {
                d[v]=d[u]+1;
                dd[v]=d[v];
                q.push(v);
            }
        }
    }
    dfs();
    for(int i=1; i<=n; i++)
    {
        cout<<dd[i]<<' ';
        edg[i].clear();
    }
    cout<<endl;

}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
//	freopen("1.txt","r",stdin);
    int _;
    cin>>_;
    while(_--)
    {
        solve();
    }
    return 0;
}