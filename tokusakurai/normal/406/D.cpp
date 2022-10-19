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

template<bool directed = false>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<vector<int>> par; //par[i][j] := j2^i
    vector<int> depth;
    const int height;

    Graph(int n) : es(n), n(n), m(0), depth(n), height(32-__builtin_clz(n)){
        par.assign(height, vector<int>(n));
    }

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void prepare(int now, int pre = -1){
        if(pre == -1) depth[now] = 0;
        par[0][now] = pre;
        for(auto &e: es[now]){
            if(e.to != pre){
                depth[e.to] = depth[now]+1;
                prepare(e.to, now);
            }
        }
    }

    void build(int root = 0){ //root
        prepare(root);
        for(int j = 0; j < height-1; j++){
            for(int i = 0; i < n; i++){
                if(par[j][i] == -1) par[j+1][i] = -1;
                else par[j+1][i] = par[j][par[j][i]];
            }
        }
    }

    int lca(int u, int v){
        if(depth[u] < depth[v]) swap(u, v);
        int D = depth[u]-depth[v];
        for(int i = 0; i < height; i++){
            if((D>>i)&1) u = par[i][u];
        }
        if(u == v) return u;
        for(int i = height-1; i >= 0; i--){
            if(par[i][u] != par[i][v]) u = par[i][u], v = par[i][v];
        }
        return par[0][u];
    }

    int dist(int u, int v){
        return depth[u]+depth[v]-2*depth[lca(u, v)];
    }
};

int main(){
    int N; cin >> N;

    vector<ll> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];

    vector<int> vs;
    int K = 0;

    Graph G(N);
    
    rep3(i, N-1, 0){
        while(K >= 2){
            int a = vs[K-2], b = vs[K-1], c = i;
            ll x1 = x[b]-x[a], y1 = y[b]-y[a];
            ll x2 = x[c]-x[b], y2 = y[c]-y[b];

            if(x1*y2-x2*y1 < 0) K--, vs.pop_back();
            else break;
        }

        if(i < N-1){
            G.add_edge(i, vs[K-1]);
            //cout << vs[K-1] << '\n';
        }

        K++, vs.eb(i);
    }
    
    G.build(N-1);
    
    int Q; cin >> Q;

    while(Q--){
        int u, v; cin >> u >> v; u--, v--;
        cout << G.lca(u, v)+1 << (Q? ' ' : '\n');
    }
}