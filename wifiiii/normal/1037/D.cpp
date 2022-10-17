#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> g[200005];
int d[200005],sz[200005],f[200005];
int l[200005],r[200005];
void dfs(int u,int fa)
{
    d[u] = d[fa] + 1, sz[u] = 1, f[u] = fa;
    for(int v:g[u])
    {
        if(v==fa) continue;
        dfs(v,u);
        sz[u] += sz[v];
    }
}
int b[200005];
int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    for(int i=1;i<=n;++i) cin>>b[i];
    for(int i=2;i<=n;++i) if(d[b[i]]<d[b[i-1]]) return cout<<"No"<<endl,0;
    int md = 0;
    for(int i=1;i<=n;++i) md = max(md, d[i]);
    for(int i=1;i<=n;++i)
    {
        if(!l[d[b[i]]]) l[d[b[i]]]=i;
        r[d[b[i]]]=i;
    }
    for(int i=3;i<=md;++i)
    {
        int now = l[i];
        for(int j=l[i-1];j<=r[i-1];++j)
        {
            for(int k=now;k<now+g[b[j]].size()-1;++k) if(f[b[k]]!=b[j]) return cout<<"No"<<endl,0;
            now=now+g[b[j]].size()-1;
        }
    }
    cout<<"Yes"<<endl;
}