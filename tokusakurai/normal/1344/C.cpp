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

vector<bool> fin;

struct Graph{
    vector<vector<int>> es;
    vector<bool> used;
    vector<int> vs, topo;
    vector<int> keep;
    const int n;

    Graph(int n) : n(n){
        es.resize(n), used.resize(n), topo.resize(n);
    }

    void add_edge(int from, int to, bool directed = true){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    bool trace(int now, int t){
        used[now] = true;
        if(now == t) {keep.eb(now); return true;}
        each(e, es[now]){
            if(used[e]) continue;
            if(trace(e, t)) {keep.eb(now); return true;}
        }
        return false;
    }

    vector<int> find_path(int s, int t){
        keep.clear(), fill(all(used), 0);
        trace(s, t), reverse(all(keep));
        return keep;
    }

    void topological_sort(int now){
        used[now] = true;
        int s = 0;
        each(e, es[now]){
            if(!used[e]) topological_sort(e);
        }
        topo[now] = sz(vs), vs.eb(now);
    }

    vector<int> find_loop(){
        keep.clear(), fill(all(used), 0);
        rep(i, n){
            if(!used[i]) topological_sort(i);
        }
        rep(i, n){
            each(e, es[i]){
                if(topo[i] <= topo[e]) return find_path(e, i);
            }
        }
        return keep;
    }

    void dfs(int now){
        if(used[now]) return;
        used[now] = true, fin[now] = true;
        each(e, es[now]){
            if(!used[e]) dfs(e);
        }
    }
};

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> u(M), v(M);
    Graph G(N);
    rep(i, M){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
        G.add_edge(v[i], u[i], true);
    }
    if(!G.find_loop().empty()) {cout << -1 << '\n'; return 0;}

    Graph G1(N), G2(N);
    rep(i, M){
        G1.add_edge(v[i], u[i], true);
        G2.add_edge(u[i], v[i], true);
    }

    fin.assign(N, false);
    int cnt = 0;
    vector<char> ans(N);
    rep(i, N){
        if(!fin[i]) cnt++, ans[i] = 'A';
        else ans[i] = 'E';
        G1.dfs(i), G2.dfs(i);
    }

    cout << cnt << '\n';
    each(e, ans) cout << e; cout << '\n';
}