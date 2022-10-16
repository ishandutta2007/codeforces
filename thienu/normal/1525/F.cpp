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

// kactl
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
struct Dinic {
    struct Edge {
        int to, rev;
        ll c, oc;
        ll flow() { return max(oc - c, 0LL); } // if you need flows
    };
    vi lvl, ptr, q;
    vector<vector<Edge>> adj;
    Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
    void addEdge(int a, int b, ll c, ll rcap = 0) {
        adj[a].push_back({b, sz(adj[b]), c, c});
        adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
    }
    ll dfs(int v, int t, ll f) {
        if (v == t || !f) return f;
        for (int& i = ptr[v]; i < sz(adj[v]); i++) {
            Edge& e = adj[v][i];
            if (lvl[e.to] == lvl[v] + 1)
                if (ll p = dfs(e.to, t, min(f, e.c))) {
                    e.c -= p, adj[e.to][e.rev].c += p;
                    return p;
                }
        }
        return 0;
    }
    ll calc(int s, int t) {
        ll flow = 0; q[0] = s;
        rep(L,0,31) do { // 'int L=30' maybe faster for random data
            lvl = ptr = vi(sz(q));
            int qi = 0, qe = lvl[s] = 1;
            while (qi < qe && !lvl[t]) {
                int v = q[qi++];
                for (Edge e : adj[v])
                    if (!lvl[e.to] && e.c >> (30 - L))
                        q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
            }
            while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
        } while (lvl[t]);
        return flow;
    }
    bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

const ll INF = 1e18;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vvi adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
    }
    Dinic dinic(2*n+2);
    int s = 2*n, t = 2*n+1;
    for(int i = 0; i < n; i++){
        dinic.addEdge(s, i, 1);
        dinic.addEdge(i+n, t, 1);
        for(int j : adj[i]){
            dinic.addEdge(i, n+j, 2);
        }
    }
    int flow = dinic.calc(s, t);
    debug(flow);
    vi ops;
    for(int i = 0; i < n; i++){
        if(!dinic.leftOfMinCut(i)){
            ops.push_back(i+1);
        }
        if(dinic.leftOfMinCut(i+n)){
            ops.push_back(-i-1);
        }
    }
    debug(ops);

    vpii waves(k);
    for(int i = 0; i < k; i++){
        int x, y;
        cin >> x >> y;
        waves[i] = {x, y};
    }

    // dp[i][j] - max score, first i rounds, path cover == j
    vvll dp(k+1, vll(n+1, -INF));
    vvll num(k+1, vll(n+1));
    dp[0][n-flow] = 0;
    for(int i = 1; i <= k; i++){
        for(int j = i+1; j <= n; j++){
            for(int x = 0; x <= j; x++){
                ll cand = dp[i-1][j-x] + max(0LL, 1LL * waves[i-1].first - 1LL * x * waves[i-1].second);
                if(dp[i][j] < cand){
                    dp[i][j] = cand;
                    num[i][j] = x;
                }
            }
        }
    }
    debug(dp, num);
    vi ans;
    int cover = max_element(dp[k].begin(), dp[k].end()) - dp[k].begin();
    debug(cover);
    int ptr = 0;
    for(int i = k; i >= 1; i--){
        ans.push_back(0);
        for(int j = 0; j < num[i][cover]; j++){
            ans.push_back(ops[ptr++]);
        }
        cover -= num[i][cover];
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i : ans){
        cout << i << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}