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

const ll MOD = 1e9 + 7;

ll mul(ll x, ll y){
    return (x * y) % MOD;
}

ll add(ll x, ll y){
    return (x + y) % MOD;
}

vi split(int x){
    vi ans;
    while(x){
        ans.push_back(x % 10);
        x /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

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

vector<vector<Edge>> adj;
vi depth;

void __print(const Edge &x) {__print(make_pair(x.to, x.weight));}

void create_road(int a, int b, int i, vector<vector<Edge>> &adj, int &nodes){
    vi nums = split(i);
    int cur = a;
    for(int i = 0; i < nums.size(); i++){
        int nxt = i+1 == nums.size() ? b : nodes;
        if(nxt == nodes){
            nodes++;
            adj.push_back(vector<Edge>());
        }
        adj[cur].push_back(Edge(cur, nxt, nums[i]));
        cur = nxt;
    }
}

vi vis;
vll ans;

void dfs(vi &nodes){
    debug(nodes);
    vector<vector<int>> dest(10);
    vector<Edge> comb_adj;
    for(int u : nodes){
        for(Edge e : adj[u]){
            comb_adj.push_back(e);
        }
    }
    sort(comb_adj.begin(), comb_adj.end(), [&](Edge a, Edge b){return a.weight < b.weight;});
    for(Edge e : comb_adj){
        int u = e.from;
        int v = e.to;
        if(!vis[v] && depth[v] == depth[u] + 1){
            vis[v] = 1;
            dest[e.weight].push_back(v);
            ans[v] = add(mul(ans[u], 10), e.weight);
        }
    }
    for(int i = 0; i < 10; i++){
        if(dest[i].empty()) continue;
        dfs(dest[i]);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    int nodes = n;
    for(int i = 1; i <= m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        create_road(x, y, i, adj, nodes);
        create_road(y, x, i, adj, nodes);
    }
    debug(adj);
    // for(int i = 0; i < nodes; i++){
    //     sort(adj[i].begin(), adj[i].end(), [&](Edge a, Edge b){return a.weight < b.weight;});
    // }
    // debug(adj);
    depth.resize(nodes);
    fill(depth.begin(), depth.end(), -1);
    queue<int> q;
    q.push(0);
    depth[0] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(Edge e : adj[u]){
            int v = e.to;
            if(depth[v] == -1){
                depth[v] = depth[u] + 1;
                q.push(v);
            }
        }
    }
    debug(depth);
    vis.resize(nodes);
    ans.resize(nodes);
    vi tmp;
    tmp.push_back(0);
    dfs(tmp);
    for(int i = 1; i < n; i++){
        cout << ans[i] << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}