#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const ll MOD = 998244353;
const int INF = 1e9 + 7;

vvi adj;
int n, m;

void bfs(vi &dist, vi &parent, int x){
    queue<int> q;
    vi vis(n);
    q.push(x);
    dist[x] = 0;
    vis[x] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(vis[u]) continue;
            dist[u] = dist[v] + 1;
            vis[u] = 1;
            parent[u] = v;
            q.push(u);
        }
    }
}

int find(int a, int b){
    vi dist_a(n, INF);
    vi dist_b(n, INF);
    vi parent_a(n, INF);
    vi parent_b(n, INF);
    bfs(dist_a, parent_a, a);
    bfs(dist_b, parent_b, b);
    debug(a, b, dist_a, dist_b);

    // find ab
    vi diam(n);
    {
        int cur = b;
        diam[b] = 1;
        while(cur != a){
            cur = parent_a[cur];
            diam[cur] = 1;
        }
    }

    debug(diam);

    ll ans = 1;
    for(int v = 0; v < n; v++){
        if(diam[v] == 0){
            int cnt = 0;
            for(int u : adj[v]){
                if(dist_a[u] + 1 == dist_a[v] && dist_b[u] + 1 == dist_b[v]) cnt++;
            }
            ans = (ans * cnt) % MOD;
        }
    }

    return ans;
}

void solve(){
    cin >> n >> m;
    adj.resize(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vvi ans(n, vi(n));
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            int x = find(i, j);
            ans[i][j] = x;
            ans[j][i] = x;
        }
    }
    debug(ans);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // int x = find(0, 0);
    // debug(x);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}