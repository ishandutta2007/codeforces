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

int INF = 1e9 + 1000;

struct Edge{
    int from;
    int to;
    int weight;
    Edge(int _from, int _to, int _weight){
        from = _from;
        to = _to;
        weight = _weight;
    }
};

void __print(Edge e){
    cerr << '{' << e.from << "->" << e.to << ", " << e.weight << '}';
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<Edge>> edges(n);
    for(int i = 0; i < m; i++){
        int f, t, w;
        cin >> f >> t >> w;
        edges[f].push_back(Edge(f, t, w));
    }
    for(int i = 0; i < n; i++){
        sort(edges[i].begin(), edges[i].end(), [&](Edge &a, Edge &b){return a.to < b.to;});
    }
    // debug(edges);
    debug("edges done");
    vvi nxt(n, vi(n, INF));
    for(int u = 0; u < n; u++){
        for(Edge e : edges[u]){
            for(int v = 0; v < n; v++){
                nxt[u][v] = min(nxt[u][v], e.weight + (v - e.to + n) % n);
            }
        }
    }
    // debug(nxt);
    debug("nxt done");
    vvi ans(n, vi(n));
    for(int i = 0; i < n; i++){
        // {time, node}
        // priority_queue<pii, vpii, greater<pii>> q;
        // q.push({0, i});
        vi vis(n);
        vi times(n, INF);
        times[i] = 0;
        vis[i] = 0;
        for(int j = 0; j < n; j++){
            // debug(q.size());
            int time = INF, u;
            // tie(time, u) = q.top();
            // find best
            for(int k = 0; k < n; k++){
                if(!vis[k] && times[k] < time){
                    time = times[k];
                    u = k;
                }
            }
            debug(u);
            // q.pop();
            vis[u] = 1;
            // iterate over destinations
            for(int v = 0; v < n; v++){
                if(vis[v]) continue;
                // q.push({time + nxt[u][(v - (time % n) + n) % n], v});
                times[v] = min(times[v], time + nxt[u][(v - (time % n) + n) % n]);
            }
        }
        for(int j = 0; j < n; j++){
            ans[i][j] = times[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}