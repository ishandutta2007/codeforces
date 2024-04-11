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
void __print(const tuple<int, int, int> &x) {cerr << '{'; __print(get<0>(x)); cerr << ','; __print(get<1>(x)); cerr << ','; __print(get<2>(x)); cerr << '}';}
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
 
using vvpii = vector<vector<pair<int, int>>>;
 
// TODO: change to 30
int MAX_INVS = 30;
int INF = 2e9 + 7;
ll MOD = 998244353;
 
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
 
void solve(){
    int n, m;
    cin >> n >> m;
 
    // less than 30 invs
    vvi adj(n);
    vvi adj_rev(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;y--;
        adj[x].push_back(y);
        adj_rev[y].push_back(x);
    }
 
    // build big graph
    vvpii adj_big(n * MAX_INVS);
    for(int i = 0; i < MAX_INVS; i++){
        for(int j = 0; j < n; j++){
            if(i & 1){
                for(int k : adj_rev[j]){
                    adj_big[i * n + j].push_back({k + i * n, 1});
                }
            }
            else{
                for(int k : adj[j]){
                    adj_big[i * n + j].push_back({k + i * n, 1});
                }
            }
            if(i + 1 < MAX_INVS) adj_big[i * n + j].push_back({(i+1) * n + j, 1 << i});
        }
    }
 
    debug(adj_big);
 
    // dijkstra from 0 to kn - 1
    vector<int> dist(n * MAX_INVS, INF);
    dist[0] = 0;
    priority_queue<pii, vpii, greater<pii>> q;
    q.push({0, 0});
    while(!q.empty()){
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if(d_v != dist[v]) continue;
        for(auto edge : adj_big[v]){
            int to = edge.first;
            int len = edge.second;
 
            if(dist[v] + len < dist[to]){
                dist[to] = dist[v] + len;
                q.push({dist[to], to});
            }
        }
    }
 
    debug(dist);
 
    int ans = INF;
    for(int i = 0; i < MAX_INVS; i++){
        ans = min(ans, dist[i * n + (n-1)]);
    }
 
    if(ans < INF){
        cout << ans % MOD << endl;
        return;
    }

 
    // dijkstra with depths
    using tiii = tuple<int, int, int>;
    using vtiii = vector<tiii>;
    using vvtiii = vector<vtiii>;

    vvtiii adj_shallow(2 * n);
    for(int i = 0; i < n; i++){
        for(int j : adj[i]){
            adj_shallow[i].push_back({j, 0, 1});
        }
        adj_shallow[i].push_back({i + n, 1, 0});
    }
    for(int i = 0; i < n; i++){
        for(int j : adj_rev[i]){
            adj_shallow[i + n].push_back({j + n, 0, 1});
        }
        adj_shallow[i + n].push_back({i, 1, 0});
    }

    debug(adj_shallow);
    
    vector<pii> dist2(2 * n, {INF, INF}); // invs, dist
    dist2[0] = {0, 0};
    priority_queue<tiii, vtiii, greater<tiii>> q2;
    q2.push({0, 0, 0});
    while(!q2.empty()){
        int v = get<2>(q2.top());
        int depth_v = get<0>(q2.top());
        int dist_v = get<1>(q2.top());
        q2.pop();
        if(depth_v != dist2[v].first || dist_v != dist2[v].second) continue;
        for(auto edge : adj_shallow[v]){
            debug(v, edge);
            int to = get<0>(edge);
            pii len = make_pair(get<1>(edge), get<2>(edge));
            if(make_pair(dist2[v].first + len.first, dist2[v].second + len.second) < dist2[to]){
                dist2[to] = make_pair(dist2[v].first + len.first, dist2[v].second + len.second);
                q2.push({dist2[to].first, dist2[to].second, to});
            }
        }
    }
 
    debug(dist2);
    int inversions, distance;
    tie(inversions, distance) = min(dist2[n-1], dist2[2 * n - 1]);
    // int inversions = dist2[n-1].first;
    // int distance = dist2[n-1].second;
    
    ll cost = ((binpow(2, inversions) - 1 + distance) % MOD + MOD) % MOD;
    cout << cost << endl;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}