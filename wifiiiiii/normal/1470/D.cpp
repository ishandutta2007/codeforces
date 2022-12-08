#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

vector<int> g[300005];
int a[300005], vis[300005];
void dfs(int u) {
    vis[u] = 1;
    int ok = 1;
    for(int v : g[u]) {
        if(a[v]) ok = 0;
    }
    a[u] = ok;
    for(int v : g[u]) {
        if(vis[v]) continue;
        dfs(v);
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i=1;i<=n;++i) vis[i] = a[i] = 0, g[i].clear();
        for(int i=1;i<=m;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1);
        int ok = 1;
        for(int i=1;i<=n;++i) {
            if(!vis[i]) ok = 0;
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int cnt = 0;
        for(int i=1;i<=n;++i) {
            if(a[i] == 1) ++cnt;
        }
        cout << cnt << endl;
        for(int i=1;i<=n;++i) {
            if(a[i] == 1) cout << i << " ";
        }
        cout << endl;
    }
}