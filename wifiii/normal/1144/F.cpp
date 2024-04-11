#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define fe(i,n) for(int i=1;i<=n;++i)
#define ff(i,n) for(int i=0;i<n;++i)
#define fs(i,s) for(int i=0;i<s.size();++i)
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

vector<int> g[200005];
int c[200005];
void dfs(int u,int col)
{
    c[u]=col;
    for(int v:g[u])
    {
        if(c[v]) continue;
        dfs(v,-col);
    }
}
pair<int,int> es[200005];
int ans[200005];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    ij
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        es[i]={u,v};
    }
    dfs(1,1);
    ij
    {
        if(c[es[i].first] * c[es[i].second] > 0)
        {
            cout<<"NO"<<endl;
            return 0;
        }
        if(c[es[i].first] > 0) ans[i]=1;
    }
    cout<<"YES"<<endl;
    ij cout<<ans[i];
    cout<<endl;
}