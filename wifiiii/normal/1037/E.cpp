#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define alll(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define endl '\n'

set<int> g[200005];
int u[200005],v[200005];
int deg[200005],ans[200005],vis[200005];
int main()
{
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;++i)
        cin>>u[i]>>v[i],deg[u[i]]++,deg[v[i]]++,g[u[i]].insert(v[i]),g[v[i]].insert(u[i]);
    queue<int> q;
    int sz = n;
    for(int i=1;i<=n;++i) if(deg[i] < k) q.push(i);
    for(int i=m;i>=1;--i)
    {
        while(!q.empty())
        {
            int p=q.front();q.pop();
            --sz;vis[p]=1;
            for(int v:g[p]) {
                deg[v]--;
                if(deg[v] == k-1) q.push(v);
            }
        }
        ans[i] = sz;
        if(!vis[v[i]] && !vis[u[i]])
        {
            deg[u[i]]--;
            if(deg[u[i]] == k-1) q.push(u[i]);
            deg[v[i]]--;
            if(deg[v[i]] == k-1) q.push(v[i]);
            g[u[i]].erase(v[i]);
            g[v[i]].erase(u[i]);
        }
    }
    ij cout<<ans[i]<<endl;
}