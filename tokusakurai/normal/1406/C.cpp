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
    vector<int> subtree_size;
    const int n;
    int u = -1, v = -1, w = -1;

    Graph(int n) : n(n){
        es.resize(n);
        subtree_size.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    int dfs(int now, int pre){
        subtree_size[now] = 1;
        for(auto &e: es[now]){
            if(e != pre) subtree_size[now] += dfs(e, now);
        }
        return subtree_size[now];
    }

    void dfs2(int now, int pre){
        if(subtree_size[now]*2 == n) u = pre;
        if(u != -1 && w == -1 && sz(es[now]) == 1) v = pre, w = now;
        for(auto &e: es[now]){
            if(e != pre) dfs2(e, now);
        }
    }

    void solve(){
        dfs(0, -1), dfs2(0, -1);
        if(u == -1){
            rep(i, 2) cout << 1 << ' ' << es[0].front()+1 << endl;
        }
        else{
            cout << v+1 << ' ' << w+1 << endl;
            cout << u+1 << ' ' << w+1 << endl;
        }
    }
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        Graph G(N);
        rep(i, N-1){
            int u, v; cin >> u >> v; u--, v--;
            G.add_edge(u, v);
        }
        G.solve();
    }
}