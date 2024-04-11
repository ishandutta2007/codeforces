#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

const int maxn = 100005;
int sz[maxn], son[maxn], mx[maxn], deg[maxn];
vi g[maxn];
int n;
void dfs(int u,int fa) {
    sz[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dfs(v, u);
        sz[u] += sz[v];
        mx[u] = max(mx[u], sz[v]);
    }
    mx[u] = max(mx[u], n - sz[u]);
}
int dfs2(int u, int fa) {
    if(deg[u] == 1) return u;
    for(int v : g[u]) {
        if(v == fa) continue;
        return dfs2(v, u);
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        ii g[i].clear(), sz[i] = mx[i] = deg[i] = 0;
        for(int i=1;i<n;++i) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        dfs(1, 0);
        int mn = n;
        ii mn = min(mn, mx[i]);
        int cnt = 0;
        ii if(mn == mx[i]) ++cnt;
        if(cnt == 1) {
            cout << 1 << " " << g[1][0] << endl;
            cout << 1 << " " << g[1][0] << endl;
        } else {
            assert(cnt == 2);
            int rt = 0, rt2 = 0;
            ii {
                if(mn == mx[i]) {
                    if(!rt) rt = i;
                    else rt2 = i;
                }
            }
            int p = dfs2(rt, rt2);
            cout << p << " " << g[p][0] << endl;
            cout << p << " " << rt2 << endl;
        }
    }
}