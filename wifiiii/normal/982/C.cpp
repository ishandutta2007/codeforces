#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
#define scsz(s,a,b) int jjj=1;for(int iii=a;iii<=b;++iii) {cout<<s[iii];if(jjj++ % 10) cout<<"\t";else cout<<"\n";}cout<<endl;
const ll mod = 1e9+7;

int vis[100005],sz[100005];
vector<int> g[100005];
int dfs(int u)
{
    vis[u] = 1;
    if(g[u].size()==0) return sz[u]=1;
    int ret = 0;
    for(int v:g[u])
    {
        if(vis[v]) continue;
        ret += dfs(v);
    }
    return sz[u]=ret+1;
}
int dfs2(int u)
{
    vis[u] = 1;
    if(sz[u]==1) return 0;
    int ret = 0;
    for(int v:g[u])
    {
        if(vis[v]) continue;
        ret += dfs2(v);
    }
    if(sz[u]%2==0) ret++;
    return ret;
}
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int u,v;cin>>u>>v;
        g[u].pb(v);g[v].pb(u);
    }
    if(n%2) {cout<<-1<<endl;return 0;}
    dfs(1);
    memset(vis,0,sizeof(vis));
    cout << dfs2(1)-1 << endl;
}