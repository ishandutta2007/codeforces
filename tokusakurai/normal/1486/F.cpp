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
    vector<vector<int>> par; //par[i][j] := j2^i
    vector<vector<pii>> ps; //LCAi
    vector<int> depth, dp, deg;
    const int n, height;
    int m;

    Graph(int n) : es(n), ps(n), depth(n), dp(n, 0), deg(n, 0), n(n), height(32-__builtin_clz(n)), m(0){
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

    void build(int root = 0){
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

    int dfs(int now, int pre = -1){
        each(e, es[now]){
            if(e.to != pre) dp[now] += dfs(e.to, now);
        }
        return dp[now];
    }

    int par_depth(int now, int k){
        int x = depth[now]-k;
        rep(i, height){
            if((x>>i)&1) now = par[i][now];
        }
        return now;
    }

    ll solve(int i, int pre = -1){
        int k = n;
        ll cnt = 0, ret = 0;

        map<pii, ll> mp1;
        map<int, ll> mp2;

        each(e, ps[i]){
            int u, v;

            if(e.first == i) u = k++;
            else u = par_depth(e.first, depth[i]+1);

            if(e.second == i) v = k++;
            else v = par_depth(e.second, depth[i]+1);

            cnt++;
            mp1[minmax(u, v)]++, mp2[u]++, mp2[v]++;    
        }

        ret += cnt*cnt;
        each(e, mp2) ret -= e.second*e.second;
        each(e, mp1) ret += e.second*e.second;
        ret /= 2;

        each(e, es[i]){
            if(e.to != pre){
                ret += dp[e.to]*(cnt-mp2[e.to]);
            }
        }
        ret += deg[i]*cnt;

        each(e, es[i]){
            if(e.to != pre) ret += solve(e.to, i);
        }

        return ret;
    }
};

int main(){
    int N; cin >> N;

    Graph G(N);

    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    G.build(0);

    int Q; cin >> Q;

    while(Q--){
        int u, v; cin >> u >> v; u--, v--;
        int l = G.lca(u, v);

        G.ps[l].eb(u, v);

        if(u != l){
            G.dp[u]++, G.deg[u]++;
            G.dp[G.par_depth(u, G.depth[l]+1)]--;
        }
        if(v != l){
            G.dp[v]++, G.deg[v]++;
            G.dp[G.par_depth(v, G.depth[l]+1)]--;
        }
    }

    G.dfs(0);

    cout << G.solve(0) << '\n';
}