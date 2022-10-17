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

int topo[200005],invtopo[200005],vis[200005],sz[200005];
vector<int> g[200005];
int I = 1;
int dfs(int u)
{
    vis[u] = 1, topo[I++] = u;
    if(g[u].size()==0) return sz[u]=1;
    int ret = 0;
    for(int v:g[u])
    {
        if(vis[v]) continue;
        ret += dfs(v);
    }
    return sz[u]=ret+1;
}
int main()
{
    ios::sync_with_stdio(0);
    int n,q;
    cin>>n>>q;
    for(int i=2;i<=n;++i)
    {
        int t; cin >> t;
        g[t].pb(i);
    }
    dfs(1);
    for(int i=1;i<I;++i) invtopo[topo[i]] = i;
    while(q--)
    {
        int u,k;cin>>u>>k;
        if(sz[u]>=k) cout << topo[invtopo[u]+k-1] << endl;
        else cout << -1 << endl;
    }
}