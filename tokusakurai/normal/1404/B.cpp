#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Graph{
    vector<vector<int>> es;
    vector<int> d;
    const int n;

    Graph(int n) : n(n){
        es.resize(n), d.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    void dfs(int now, int pre){
        for(auto &e: es[now]){
            if(e == pre) continue;
            d[e] = d[now]+1, dfs(e, now);
        }
    }

    int farthest_point(int s){
        d[s] = 0, dfs(s, -1);
        int ret = -1, t = -1;
        rep(i, n) if(chmax(ret, d[i])) t = i;
        return t;
    }

    pair<int, pii> diameter(){
        int s = farthest_point(0), t = farthest_point(s);
        return {d[t], {s, t}};
    }
};

template<typename T>
struct Weighted_Graph{
    struct edge{
        int to; T cost;
        edge(int to, T cost) : to(to), cost(cost) {}
    };

    vector<vector<edge>> es;
    vector<T> d;
    const T INF_T;
    const int n;

    Weighted_Graph(int n) : INF_T(numeric_limits<T>::max()), n(n){
        es.resize(n), d.resize(n);
    }

    void add_edge(int from, int to, T cost, bool directed = false){
        es[from].eb(to, cost);
        if(!directed) es[to].eb(from, cost);
    }

    void dfs(int now, int pre){
        for(auto &e: es[now]){
            if(e.to == pre) continue;
            d[e.to] = d[now]+e.cost, dfs(e.to, now);
        }
    }

    int farthest_point(int s){
        d[s] = 0, dfs(s, -1);
        int ret = -1, t = -1;
        rep(i, n) if(chmax(ret, d[i])) t = i;
        return t;
    }

    pair<T, pii> diameter(){
        int s = farthest_point(0), t = farthest_point(s);
        return {d[t], {s, t}};
    }
};

int main(){
    int T;
    cin >> T;
    vector<string> ans;
    while(T--){
        int N, a, b, x, y;
        cin >> N >> a >> b >> x >> y;
        a--, b--;
        Weighted_Graph<int> G(N);
        rep(i, N-1){
            int u, v; cin >> u >> v; u--, v--;
            G.add_edge(u, v, 1);
        }
        int r = G.diameter().first;
        chmin(y, r);
        if(2*x >= y) {ans.pb("Alice"); continue;}
        G.farthest_point(b);
        if(G.d[a] <= x) ans.pb("Alice");
        else ans.pb("Bob");
    }
    for(auto &e: ans) cout << e << endl;
}