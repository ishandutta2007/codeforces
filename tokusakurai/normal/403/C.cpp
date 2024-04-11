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

template<bool directed = true>
struct Strongly_Connected_Components{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es, rs;
    vector<int> vs, comp;
    vector<bool> used;
    const int n;
    int m;

    Strongly_Connected_Components(int n) : es(n), rs(n), vs(n), comp(n), used(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m), rs[to].emplace_back(from, m);
        if(!directed) es[to].emplace_back(from, m), rs[from].emplace_back(to, m);
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

    int operator [] (int k) const {return comp[k];}
};

int main(){
    int N; cin >> N;

    Strongly_Connected_Components scc(N);

    rep(i, N){
        rep(j, N){
            int x; cin >> x;
            if(x > 0) scc.add_edge(i, j);
        }
    }

    cout << (scc.decompose().n == 1? "YES\n" : "NO\n");
}