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

const ll INF = 1'000'000'000'000'000'009;

void solve(){
    int n, m;
    cin >> n >> m;
    vvi edges(n, vi(n, -1));
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edges[u][v] = w;
        edges[v][u] = w;
    }

    vvll distance(n, vll(n, INF));
    for(int i = 0; i < n; i++){
        distance[i][i] = 0;
        for(int j = 0; j < n; j++){
            if(edges[i][j] != -1){
                distance[i][j] = edges[i][j];
            }
        }
    }
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    debug(distance);

    // in_edges[begin][end]
    vvi in_edges(n, vi(n));
    for(int begin = 0; begin < n; begin++){
        for(int end = 0; end < n; end++){
            if(begin == end) continue;
            for(int u = 0; u < n; u++){
                if(u == end) continue;
                if(edges[u][end] == -1) continue;
                if(distance[begin][u] + edges[u][end] == distance[begin][end]){
                    in_edges[begin][end]++;
                }
            }
        }
    }
    debug(in_edges);

    vvi ans(n, vi(n));
    for(int begin = 0; begin < n; begin++){
        for(int end = 0; end < n; end++){
            for(int u = 0; u < n; u++){
                if(u == begin) continue;
                if(distance[begin][u] + distance[u][end] == distance[begin][end]){
                    ans[begin][end] += in_edges[begin][u];
                }
            }
        }
    }
    debug(ans);

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            cout << ans[i][j] << ' ';
        }
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}