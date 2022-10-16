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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

struct DSU{
    int n;
    vi par, sz;
    DSU(int n) : n(n) {
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.resize(n);
        fill(sz.begin(), sz.end(), 1);
    }

    int find_par(int u){
        if(par[u] == u) return u;
        return par[u] = find_par(par[u]);
    }

    bool merge(int u, int v){
        debug(u, v);
        u = find_par(u), v = find_par(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) swap(u, v);
        par[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<set<int>> adj(n);
    vector<pair<int, pii>> edges;
    int xo = 0;
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;y--;
        adj[x].insert(y);
        adj[y].insert(x);
        edges.push_back({w, {x, y}});
        xo ^= w;
    }
    sort(edges.begin(), edges.end());

    DSU all(n), nonzero(n);

    // build all
    queue<int> q;
    vi vis(n);
    set<int> unvisited;
    int tot = 0;
    for(int i = 0; i < n; i++) unvisited.insert(i);
    for(int i = 0; i < n; i++){
        if(vis[i]) continue;
        q.push(i);
        vis[i] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            vi to_remove;
            for(int v : unvisited){
                if(u != v && adj[u].find(v) == adj[u].end()){
                    to_remove.push_back(v);
                    vis[v] = 1;
                    q.push(v);
                    tot += all.merge(u, v);
                }
            }
            for(int i : to_remove){
                unvisited.erase(i);
            }
        }
    }
    debug(all.par);
    debug(tot);

    int ex = ((ll) tot == 1LL * n * (n-1) / 2 - m) ? xo : 0;
    debug(ex);

    int ans = 0;
    for(auto e : edges){
        int w, x, y;
        w = e.first;
        tie(x, y) = e.second;
        if(all.merge(x, y)){
            ans += w;
            nonzero.merge(x, y);
        }else if(nonzero.merge(x, y)){
            ex = min(ex, w);
        }
    }
    cout << ans + ex << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}