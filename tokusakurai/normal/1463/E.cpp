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

struct Graph{
    vector<vector<int>> es;
    const int n;

    Graph(int n) : n(n){
        es.resize(n);
    }

    void add_edge(int from, int to, bool directed = true){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }
};

struct Strongly_Connected_Components{
    vector<vector<int>> es, rs;
    vector<int> vs, comp;
    vector<bool> used;
    const int n;

    Strongly_Connected_Components(int n) : n(n){
        es.resize(n), rs.resize(n);
        vs.resize(n), comp.resize(n), used.resize(n);
    }

    void add_edge(int from, int to, bool directed = true){
        es[from].pb(to), rs[to].pb(from);
        if(!directed) es[to].pb(from), rs[from].pb(to);
    }

    void topological_sort(int now){
        used[now] = true;
        each(e, es[now]) if(!used[e]) topological_sort(e);
        vs.pb(now);
    }

    void track_back(int now, int cnt){
        used[now] = true, comp[now] = cnt;
        each(e, rs[now]) if(!used[e]) track_back(e, cnt);
    }

    Graph decompose(){
        fill(all(used), false);
        rep(i, n) if(!used[i]) topological_sort(i);
        fill(all(used), false), reverse(all(vs));
        int cnt = 0;
        each(e, vs) if(!used[e]) track_back(e, cnt++);
        Graph G(cnt);
        rep(i, n){
            for(auto &e: es[i]){
                int u = comp[i], v = comp[e];
                if(u != v) G.add_edge(u, v, true);
            }
        }
        return G;
    }

    int operator [] (int k) const {return comp[k];}
};

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> p(N);
    rep(i, N) {cin >> p[i]; p[i]--;}

    vector<int> x(K), y(K);
    vector<int> deg1(N, 0), deg2(N, 0);
    vector<int> nxt(N, -1);
    
    rep(i, K){
        cin >> x[i] >> y[i]; x[i]--, y[i]--;
        deg1[x[i]]++, deg2[y[i]]++;
        nxt[x[i]] = y[i];
    }
    rep(i, N){
        if(deg1[i] >= 2 || deg2[i] >= 2) {cout << 0 << '\n'; return 0;}
    }

    vector<int> pre(N), ord(N, 0), root(N, 0);
    iota(all(pre), 0), iota(all(root), 0);
    int cnt = 0;

    rep(i, N){
        if(deg2[i] > 0) continue;
        int ptr = i;
        while(nxt[ptr] != -1){
            ord[nxt[ptr]] = ord[ptr]+1;
            pre[nxt[ptr]] = ptr;
            root[nxt[ptr]] = i;
            ptr = nxt[ptr];
            cnt++;
        }
    }

    if(cnt != K) {cout << 0 << '\n'; return 0;}

    rep(i, N){
        if(p[i] == -1) continue;
        if(root[p[i]] == root[i]){
            if(ord[p[i]] > ord[i]) {cout << 0 << '\n'; return 0;}
        }
    }

    Strongly_Connected_Components G(N);

    rep(i, N){
        if(p[i] == -1) continue;
        G.add_edge(root[p[i]], root[i], true);
    }

    int n = G.decompose().n;
    if(n != N) {cout << 0 << '\n'; return 0;}

    vector<vector<int>> ids(N);
    rep(i, N){
        if(deg2[i] != 0) continue;
        int j = G[i], ptr = i;
        while(ptr != -1){
            ids[j].eb(ptr);
            ptr = nxt[ptr];
        }
    }

    each(e, ids){
        each(u, e) cout << u+1 << ' ';
    }
    cout << '\n';
}