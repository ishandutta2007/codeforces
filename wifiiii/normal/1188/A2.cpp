#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)

const int maxn = 1005;
int in[maxn];
int t1,t2;
struct edge {
    int v,w;
};
vector<edge> g[maxn];
void dfs(int u,int fa)
{
    if(in[u]==1)
    {
        if(!t1) t1=u;
        t2=u;
    }
    for(edge e:g[u])
    {
        if(e.v == fa) continue;
        dfs(e.v, u);
    }
}
struct Ans {
    int a,b,c;
};
vector<Ans> ans;
void add(int a,int b,int c)
{
    if(a==b || !c) return;
    ans.push_back({a,b,c});
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        in[u]++,in[v]++;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    forii if(in[i]==2) {cout<<"NO"<<endl;return 0;}
    cout<<"YES"<<endl;
    for(int u=1;u<=n;++u)
    {
        for(edge e:g[u])
        {
            int v=e.v,w=e.w;
            if(v<u) continue;
            int a1,a2,b1,b2;
            t1=t2=0;
            dfs(u,v);
            a1=t1,a2=t2;
            t1=t2=0;
            dfs(v,u);
            b1=t1,b2=t2;
            add(a1,b1,w/2);
            add(a2,b2,w/2);
            add(a1,a2,-w/2);
            add(b1,b2,-w/2);
        }
    }
    cout<<ans.size()<<endl;
    for(auto p:ans) cout<<p.a<<" "<<p.b<<" "<<p.c<<endl;
}