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
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

vector<int> g[200005],rg[200005];
int vis[200005],vis2[200005];
char res[200005];
int deg[200005];
void dfs1(int u) {
    vis[u]=1;
    for(int v:g[u]) if(!vis[v]) dfs1(v);
}
void dfs2(int u) {
    vis2[u]=1;
    for(int v:rg[u]) if(!vis2[v]) dfs2(v);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        rg[v].push_back(u);
        deg[v]++;
    }
    int ans=0;
    queue<int> q;
    for(int i=1;i<=n;++i) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        int cur=q.front(); q.pop();
        for(int v : g[cur]) {
            if(--deg[v] == 0) {
                q.push(v);
            }
        }
    }
    for(int i=1;i<=n;++i) if(deg[i]) return cout << -1 << endl, 0;
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;++i) {
        if(vis[i] || vis2[i]) {
            dfs1(i);
            dfs2(i);
            continue;
        }
        dfs1(i);
        dfs2(i);
        ++ans;
        res[i]='A';
    }
    cout<<ans<<endl;
    ii if(res[i]=='A') cout<<'A';else cout<<'E';
    cout<<endl;
}