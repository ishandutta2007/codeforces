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
    int from, to, x, y;
    Edge(int _from, int _to, int _x, int _y){
        from = _from;
        to = _to;
        x = _x;
        y = _y;
    }
};

const bool operator< (const Edge &a, const Edge &b){
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

vector<set<Edge>> adj;

void path(Edge e, vi &ecycle){
    int v = e.to;
    while(!adj[v].empty()){
        Edge e = *adj[v].begin();
        // auto it = lower_bound(adj[e.from].begin(), adj[e.from].end(), e);
        adj[e.from].erase(e);
        // it = lower_bound(adj[e.to].begin(), adj[e.to].end(), Edge(e.to, e.from, e.y, e.x));
        adj[e.to].erase(Edge(e.to, e.from, e.y, e.x));
        path(e, ecycle);
        ecycle.push_back(e.y);
        ecycle.push_back(e.x);
    }
}

void solve(){
    int n;
    cin >> n;
    vi color(2 * n);
    for(int i = 0; i < 2*n; i++) cin >> color[i];
    int ans = -1;
    for(int cand = 0; cand <= 20; cand++){
        int m = 1 << cand;
        int mask = (1 << cand) - 1;
        // vector<set<Edge>> adj(m);
        vector<vector<int>> adj2(m);
        for(int i = 0; i < 2*n; i+=2){
            adj2[color[i]&mask].push_back(color[i+1]&mask);
            adj2[color[i+1]&mask].push_back(color[i]&mask);
        }
        // check connectivity
        vi vis(m);
        vis[color[0]&mask] = 1;
        queue<int> q;
        q.push(color[0]&mask);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj2[u]){
                if(vis[v]) continue;
                vis[v] = 1;
                q.push(v);
            }
        }
        bool connected = true;
        for(int i = 0; i < m; i++){
            if(!vis[i] && !adj2[i].empty()){
                connected = false;
                break;
            }
        }
        if(!connected) break;
        // check degrees
        bool has_cycle = true;
        for(int i = 0; i < m; i++){
            if(adj2[i].size() & 1){
                has_cycle = false;
                break;
            }
        }
        if(!has_cycle) break;
        ans = cand;
    }
    
    cout << ans << endl;
    vi cycle;
    {
        int cand = ans;
        int m = 1 << cand;
        int mask = (1 << cand) - 1;
        // vector<set<Edge>> adj(m);
        adj.clear();
        adj.resize(m);
        for(int i = 0; i < 2*n; i+=2){
            adj[color[i]&mask].insert(Edge(color[i]&mask, color[i+1]&mask, i, i+1));
            adj[color[i+1]&mask].insert(Edge(color[i+1]&mask, color[i]&mask, i+1, i));
        }

        // get cycle
        path(Edge(-1, color[0] & mask, -1, -1), cycle);
    }
    debug(cycle);
    for(int i = 0; i < 2*n; i++){
        cout << cycle[i]+1 << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}