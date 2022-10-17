#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i )
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define endl '\n'

const int maxn = 10;
vector<int> g[maxn];
int a[maxn];
int n,m;
int vis[7][7];
void init()
{
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=6;++i)
        for(int j=i;j<=6;++j)
            vis[i][j]=0;
}
pair<int,int> es[300];
int ans;
void dfs(int p)
{
    if(p > n)
    {
        init();
        int cnt = 0;
        for(int i=1;i<=m;++i)
        {
            int u = es[i].first , v = es[i].second;
            if(a[u] > a[v]) swap(u,v);
            if(vis[a[u]][a[v]]) continue;
            vis[a[u]][a[v]] = 1;
            cnt++;
        }
        ans = max(ans, cnt);
        return;
    }
    for(int i=1;i<=6;++i)
    {
        a[p] = i;
        dfs(p+1);
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        es[i]={u,v};
    }
    dfs(1);
    cout << ans << endl;
}