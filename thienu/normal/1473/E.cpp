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

using vvpii = vector<vpii>;

const ll INF = 1'234'567'890'123'456'789LL;

vll dijkstra(vvpii adj, int n){
    vll dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    pq.push({0, 0});
    while(!pq.empty()){
        ll d; int u;
        tie(d, u) = pq.top();
        pq.pop();
        if(dist[u] != d) continue;
        for(pii p : adj[u]){
            int v, w;
            tie(v, w) = p;
            ll cand = dist[u] + w;
            if(cand < dist[v]){
                dist[v] = cand;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vvpii adj(n);
    for(int i = 0; i < m; i++){
        int x, y, w;
        cin >> x >> y >> w;
        x--;y--;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
    // debug(dijkstra(adj, n));
    vll ans(n, INF);
    ans[0] = 0;
    for(pii p : adj[0]){
        ans[p.first] = p.second; 
    }
    
    vvpii adj1(3*n), adj2(3*n);
    for(int u = 0; u < n; u++){
        for(pii p : adj[u]){
            int v, w;
            tie(v, w) = p;

            // adj1, max->min
            adj1[u].push_back({v, w});
            adj1[u+n].push_back({v+n, w});
            adj1[u+2*n].push_back({v+2*n, w});
            adj1[u].push_back({v+n, 0});
            adj1[u+n].push_back({v+2*n, w*2});

            // adj2, min->max
            adj2[u].push_back({v, w});
            adj2[u+n].push_back({v+n, w});
            adj2[u+2*n].push_back({v+2*n, w});
            adj2[u].push_back({v+n, w*2});
            adj2[u+n].push_back({v+2*n, 0});
        }
    }

    vll d1 = dijkstra(adj1, 3*n);
    vll d2 = dijkstra(adj2, 3*n);
    for(int i = 0; i < n; i++){
        ans[i] = min({ans[i], d1[2*n+i], d2[2*n+i]});
    }
    
    for(int i = 1; i < n; i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}