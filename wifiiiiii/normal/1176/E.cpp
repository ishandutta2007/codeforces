
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=1;i<=n;++i)
typedef long long ll;

vector<int> g[200005],A,B;
int vis[200005], c[200005];
void dfs(int u, int p)
{
    vis[u] = 1, c[u] = p;
    for(int v:g[u])
    {
        if(vis[v]) continue;
        dfs(v,3-p);
    }
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        memset(vis, 0, sizeof(int) * (n+1));
        while(m--)
        {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n==1) {cout<<"1\n1\n";continue;}
        dfs(1,1);
        rep(i,n) if(c[i]==1) A.push_back(i);else B.push_back(i);
        vector<int> *ans = &A;
        if(A.size() > B.size()) ans = &B;
        cout<<ans->size()<<endl;
        for(int i:*ans) cout<<i<<" ";cout<<endl;
        A.clear();B.clear();
        rep(i,n) g[i].clear();
    }
}