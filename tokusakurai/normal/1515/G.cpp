#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template<bool directed = true>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    Graph(int n) : es(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }
};

template<typename T, bool directed = true>
struct Strongly_Connected_Components{
    struct edge{
        int to, id;
        T cost;
        edge(int to, int id, T cost) : to(to), id(id), cost(cost) {}
    };

    vector<vector<edge>> es, rs;
    vector<int> vs, comp;
    vector<bool> used;
    const int n;
    int m;

    Strongly_Connected_Components(int n) : es(n), rs(n), vs(n), comp(n), used(n), n(n), m(0) {}

    void add_edge(int from, int to, T cost){
        es[from].emplace_back(to, m, cost), rs[to].emplace_back(from, m, cost);
        if(!directed) es[to].emplace_back(from, m, cost), rs[from].emplace_back(to, m, cost);
        m++;
    }

    void _dfs(int now){
        used[now] = true;
        for(auto &e: es[now]){
            if(!used[e.to]) _dfs(e.to);
        }
        vs.push_back(now);
    }

    void _rdfs(int now, int cnt){
        used[now] = true, comp[now] = cnt;
        for(auto &e: rs[now]){
            if(!used[e.to]) _rdfs(e.to, cnt);
        }
    }

    Graph<true> decompose(){
        fill(begin(used), end(used), false);
        for(int i = 0; i < n; i++){
            if(!used[i]) _dfs(i);
        }
        fill(begin(used), end(used), false), reverse(begin(vs), end(vs));
        int cnt = 0;
        for(auto &e: vs){
            if(!used[e]) _rdfs(e, cnt++);
        }
        Graph<true> G(cnt);
        for(int i = 0; i < n; i++){
            for(auto &e: es[i]){
                int u = comp[i], v = comp[e.to];
                if(u != v) G.add_edge(u, v);
            }
        }
        return G;
    }

    vector<T> d, g;

    void dfs(int now, int i){
        used[now] = true;
        each(e, es[now]){
            if(comp[e.to] != i) continue;
            if(used[e.to]){
                g[i] = gcd(g[i], abs(d[now]+e.cost-d[e.to]));
            }
            else{
                d[e.to] = d[now]+e.cost;
                dfs(e.to, i);
            }
        }
    }

    void build(){
        d.assign(n, 0), g.assign(n, 0);
        fill(all(used), false);

        rep(i, n){
            if(!used[i]){
                dfs(i, comp[i]);
            }
        }
    }

    int operator [] (int k) const {return comp[k];}
};

int main(){
    int N, M; cin >> N >> M;
    
    Strongly_Connected_Components<ll, true> G(N);

    rep(i, M){
        int u, v; ll c; cin >> u >> v >> c; u--, v--;
        G.add_edge(u, v, c);
    }

    G.decompose();
    G.build();

    //rep(i, N) cout << G.g[i] << ' '; cout << '\n';

    int Q; cin >> Q;
    
    while(Q--){
        int u; ll s, t; cin >> u >> s >> t; u--;
        ll x = gcd(G.g[G[u]], t);
        cout << (s%x == 0? "YES\n" : "NO\n");
    }
}