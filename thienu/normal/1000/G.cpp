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

struct Edge{
    int to, weight;
    Edge(int _to, int _weight) : to(_to), weight(_weight) {};
};
bool operator<(Edge a, Edge b){
    return a.to < b.to || (a.to == b.to && a.weight < b.weight);
}

void st_set(vll &st, int tl, int tr, int pos, int idx, ll val){
    if(tl == tr){
        st[pos] = val;
        return;
    }
    if(idx <= tl + (tr - tl) / 2){
        st_set(st, tl, tl + (tr - tl) / 2, pos*2, idx, val);
    }else{
        st_set(st, tl + (tr - tl) / 2 + 1, tr, pos*2+1, idx, val);
    }
    st[pos] = st[2 * pos] + st[2 * pos + 1];
}

void st_add(vll &st, int tl, int tr, int pos, int idx, ll val){
    if(tl == tr){
        st[pos] += val;
        return;
    }
    if(idx <= tl + (tr - tl) / 2){
        st_add(st, tl, tl + (tr - tl) / 2, pos*2, idx, val);
    }else{
        st_add(st, tl + (tr - tl) / 2 + 1, tr, pos*2+1, idx, val);
    }
    st[pos] = st[2 * pos] + st[2 * pos + 1];
}

ll st_sum(vll &st, int tl, int tr, int pos, int left, int right){
    if(tr < left || right < tl){
        return 0;
    }
    if(left <= tl && tr <= right){
        return st[pos];
    }
    return st_sum(st, tl, tl + (tr - tl) / 2, pos * 2, left, right)
            + st_sum(st, tl + (tr - tl) / 2 + 1, tr, pos * 2 + 1, left, right);
}

const int L = 20;
const int N = 3e5 + 69;

vector<set<Edge>> adj;
map<pii, int> weight;
int n, q;
vi depth, parent;
vi a;
vvi lift;
vll dp, subtree;
map<pii, ll> branch;

// {lca, query#}
vector<vector<pair<int, int>>> qb;
vll ans;

void dfs(int u, int last, int d){
    depth[u] = d;
    parent[u] = last;
    for(Edge e : adj[u]){
        if(e.to == last) continue;
        dfs(e.to, u, d+1);
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    // debug(a, b);
    // lift a up to b
    for(int i = L-1; i >= 0; i--){
        if(depth[a] - (1<<i) >= depth[b]){
            a = lift[i][a];
            // debug(i);
        }
    }
    // debug(a, b);
    if(a == b) return a;
    for(int i = L-1; i >= 0; i--){
        if(lift[i][a] != lift[i][b]){
            a = lift[i][a];
            b = lift[i][b];
        }
    }
    return parent[a];
}

void dfs2(int u){
    subtree[u] = a[u];
    for(Edge e : adj[u]){
        if(e.to == parent[u]) continue;
        dfs2(e.to);
        subtree[u] += max(0LL, subtree[e.to] - 2 * e.weight);
    }
}

void dfs3(int u){
    dp[u] = a[u];
    for(Edge e : adj[u]){
        ll val = max(0LL, subtree[e.to] - 2 * e.weight);
        branch[{u, e.to}] = val;
        dp[u] += val;
    }
    for(Edge e : adj[u]){
        if(e.to == parent[u]) continue;
        subtree[u] = dp[u] - branch[{u, e.to}];
        dfs3(e.to);
    }
}

vi path;
vll st(4 * N);

void dfs4(int u){
    path.push_back(u);
    st_set(st, 0, N-1, 1, depth[u], dp[u] - branch[{u, parent[u]}] - 1LL * weight[{u, parent[u]}]);

    // process queries
    for(pii p : qb[u]){
        int l, qn;
        tie(l, qn) = p;
        ans[qn] += st_sum(st, 0, N-1, 1, depth[l]+1, depth[u]);
        ans[qn] -= branch[{l, path[depth[l]+1]}];
    }

    // dfs
    for(Edge e : adj[u]){
        if(e.to == parent[u]) continue;
        st_add(st, 0, N-1, 1, depth[u], -branch[{u, e.to}]);
        dfs4(e.to);
        st_add(st, 0, N-1, 1, depth[u], branch[{u, e.to}]);
    }

    st_set(st, 0, N-1, 1, depth[u], 0);
    path.pop_back();
}

void solve(){
    cin >> n >> q;
    adj.resize(n);
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vpii queries;
    for(int i = 0; i < n-1; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;
        y--;
        adj[x].insert(Edge(y, w));
        adj[y].insert(Edge(x, w));
        weight[{x, y}] = w;
        weight[{y, x}] = w;
    }
    for(int i = 0; i < q; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        queries.push_back({a, b});
    }

    depth.resize(n);
    parent.resize(n);


    dfs(0, -1, 0);
    debug(depth, parent);

    lift.resize(L);
    fill(lift.begin(), lift.end(), vi(n));
    for(int i = 0; i < n; i++){
        lift[0][i] = parent[i];
    }
    for(int i = 1; i < L; i++){
        for(int j = 0; j < n; j++){
            lift[i][j] = (lift[i-1][j] == -1) ? -1 : (lift[i-1][lift[i-1][j]]);
        }
    }
    debug(lift);

    dp.resize(n);
    subtree.resize(n);
    dfs2(0);
    debug(subtree);
    dfs3(0);
    debug(dp);
    debug(branch);

    qb.resize(n);
    ans.resize(q);

    for(int i = 0; i < q; i++){
        int a, b;
        tie(a, b) = queries[i];
        int l = lca(a, b);
        if(a != l) qb[a].push_back({l, i});
        if(b != l) qb[b].push_back({l, i});
        ans[i] = dp[l];
    }
    debug(qb);

    dfs4(0);

    debug(ans);

    for(ll i : ans){
        cout << i << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}