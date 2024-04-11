
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

// kactl LineContainer

struct Line {
    mutable ll k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    static const ll inf = LLONG_MAX;
    ll div(ll a, ll b) { // floored division
        return a / b - ((a ^ b) < 0 && a % b); }
    bool isect(iterator x, iterator y) {
        if (y == end()) return x->p = inf, 0;
        if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
        else x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    // y = kx + m
    void add(ll k, ll m) {
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.k * x + l.m;
    }
};

struct Edge{
    int from, to;
    ll weight;
    Edge(int from, int to, ll weight) : from(from), to(to), weight(weight) {}
};

using ve = vector<Edge>;
using vve = vector<ve>;

const ll INF = 1000000000000000000;

void multi_dijkstra(int n, vll &dist, vve &adj){
    vi vis(n);
    set<pair<ll, int>> sdist;
    for(int i = 0; i < n; i++){
        sdist.insert({dist[i], i});
    }

    while(!sdist.empty()){
        pair<ll, int> p = *sdist.begin();
        sdist.erase(sdist.begin());

        ll d;
        int v;
        tie(d, v) = p;

        vis[v] = 1;

        for(Edge e : adj[v]){
            if(vis[e.to]) continue;
            
            if(dist[v] + e.weight < dist[e.to]){
                sdist.erase({dist[e.to], e.to});
                dist[e.to] = dist[v] + e.weight;
                sdist.insert({dist[e.to], e.to});
            }
        }
    }
}

void take_flight(int n, vll &dist){
    LineContainer ln;
    for(int i = 0; i < n; i++){
        ln.add(2*i, -dist[i]-1LL * i * i);
    }

    for(int i = 0; i < n; i++){
        dist[i] = -ln.query(i) + 1LL * i * i;
    }
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vve adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        ll w;
        cin >> x >> y >> w;
        x--;
        y--;
        adj[x].push_back(Edge(x, y, w));
        adj[y].push_back(Edge(y, x, w));
    }

    vll dist(n, INF);
    dist[0] = 0;

    for(int i = 0; i < k; i++){
        multi_dijkstra(n, dist, adj);
        take_flight(n, dist);
    }
    multi_dijkstra(n, dist, adj);
    debug(dist);

    for(int i = 0; i < n; i++){
        cout << dist[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}