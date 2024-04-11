#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define pb push_back
int par[100005],c[100005],m[100005];
vector<int>ans;
vector<int> g[100005];
bool dfs(int u)
{
    int f = 1;
    for(int v:g[u])
    {
        if(!c[v]) f = 0;
        dfs(v);
    }
    if(c[u]&&f) ans.pb(u);
}
int main()
{
    int n;
    cin>>n;
    int rt;
    for(int i=1;i<=n;++i)
    {
        int a,b;
        cin>>a>>b;
        if(a==-1) rt=i;
        else g[a].pb(i);
        c[i]=b;
    }
    //for(int i=1;i<=n;++i) sort(g[i].begin(),g[i].end());
    dfs(rt);
    sort(ans.begin(),ans.end());
    if(ans.size()) for(int i:ans) cout<<i<<" ";
    else cout<<-1;
    cout<<endl;
}