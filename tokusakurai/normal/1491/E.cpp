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

vector<int> F;

template<bool directed = false>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    vector<int> si, par;
    vector<bool> used, used_e;
    const int n;
    int m;

    Graph(int n) : es(n), si(n), par(n), used(n, false), used_e(n-1, false), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    int calc_size(int now, int pre = -1){
        si[now] = 1;
        for(auto &e: es[now]){
            if(e.to == pre || used_e[e.id]) continue;
            si[now] += calc_size(e.to, now);
        }
        return si[now];
    }

    pair<int, int> search_centroid(int now, int sz, int pre = -1){ //()
        pair<int, int> ret = make_pair(INT_MAX, -1);
        int M = 0, S = 1;
        for(auto &e: es[now]){
            if(e.to == pre || used_e[e.id]) continue;
            ret = min(ret, search_centroid(e.to, sz, now));
            M = max(M, si[e.to]);
            S += si[e.to];
        }
        M = max(M, sz-S);
        ret = min(ret, make_pair(M, now));
        return ret;
    }

    int find_centroid(int s){
        calc_size(s);
        return search_centroid(s, si[s]).second;
    }

    int dfs(int now, int k, vector<int> &v, int pre = -1){
        si[now] = 1;
        for(auto &e: es[now]){
            if(e.to == pre || used_e[e.id]) continue;
            par[e.to] = e.id;
            si[now] += dfs(e.to, k, v, now);
        }
        if(si[now] == F[k-2]) v.eb(now);
        return si[now];
    }

    bool solve(int now, int k){ //F[k]
        if(k <= 1) return true;

        int c = find_centroid(now);
        
        vector<int> v;
        dfs(c, k, v);
        
        if(v.empty()) return false;

        bool ret = true;
        used_e[par[v[0]]] = true;

        if(!solve(v[0], k-2)) ret = false;
        if(!solve(c, k-1)) ret = false;

        return ret;
    }

    void decompose(int root = 0){
        calc_size(root);
        int c = search_centroid(root, si[root]).second;
        used[c] = true;
        for(auto &e: es[c]){
            if(!used[e.to]) decompose(e.to);
        }
    }
};

int main(){
    int N; cin >> N;

    F.eb(1), F.eb(1);

    int now = 1;
    while(true){
        now += F[sz(F)-2];
        if(now > N) break;
        F.eb(now);
    }
    
    Graph G(N);
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }
    
    if(F.back() != N) {cout << "NO\n"; return 0;}

    cout << (G.solve(0, sz(F)-1)? "YES\n" : "NO\n");
}