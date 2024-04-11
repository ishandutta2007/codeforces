#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
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
typedef pair<int, int> pii;

const int maxn = 200005;
vector<int> g[maxn];
int deg[maxn], dep[maxn], tag[maxn], f[maxn];
void dfs(int u, int fa) {
    if(dep[u] <= 2) tag[u] = 1;
    for(int v : g[u]) {
        if(v == fa) continue;
        dep[v] = dep[u] + 1;
        deg[u]++;
        dfs(v, u);
        f[v] = u;
    }
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i=1;i<n;++i) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int ans = 0;
    queue<int> q;
    for(int i=1;i<=n;++i) if(!deg[i]) q.push(i);
    while(!q.empty()) {
        int cur = q.front(); q.pop();
        if(tag[cur] == 2) {
            tag[f[cur]] = max(tag[f[cur]], 1);
        } else if(tag[cur] == 0) {
            if(tag[f[cur]] != 2) {
//                cout << "give tag to " << f[cur] << endl;
                tag[f[cur]] = 2;
                ++ans;
            }
        }
        if(--deg[f[cur]] == 0) {
            q.push(f[cur]);
        }
    }
    cout << ans << endl;
}