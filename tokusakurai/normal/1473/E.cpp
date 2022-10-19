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

template<typename T>
struct Weighted_Graph{
    struct edge{
        int to; T cost;
        edge(int to, T cost) : to(to), cost(cost) {}
    };

    vector<vector<edge>> es;
    vector<T> d;
    vector<int> pre_v;
    vector<int> keep;
    const T INF_T;
    const int n;

    Weighted_Graph(int n) : INF_T(numeric_limits<T>::max()/2), n(n){
        es.resize(n), d.resize(n), pre_v.resize(n);
    }

    void add_edge(int from, int to, T cost, bool directed = false){
        es[from].eb(to, cost);
        if(!directed) es[to].eb(from, cost);
    }

    T dijkstra(int s, int t = 0){
        fill(all(d), INF_T);
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P> > que;
        que.emplace(d[s] = 0, s);
        while(!que.empty()){
            auto [p, i] = que.top(); que.pop();
            if(p > d[i]) continue;
            each(e, es[i]){
                if(chmin(d[e.to], d[i]+e.cost)){
                    pre_v[e.to] = i, que.emplace(d[e.to], e.to);
                }
            }
        }
        return d[t];
    }

    vector<int> shortest_path(int s, int t){
        keep.clear();
        if(dijkstra(s, t) == INF_T) return keep;
        for(int now = t; now != s; now = pre_v[now]) keep.pb(now);
        keep.pb(s), reverse(all(keep));
        return keep;
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    Weighted_Graph<ll> G(4*N);

    rep(i, M){
        int u, v; ll c; cin >> u >> v >> c; u--, v--;
        rep(j, 4) G.add_edge(N*j+u, N*j+v, c, false);
        G.add_edge(u, N+v, 2*c, true), G.add_edge(v, N+u, 2*c, true);
        G.add_edge(2*N+u, 3*N+v, 2*c, true), G.add_edge(2*N+v, 3*N+u, 2*c, true);
        G.add_edge(u, 2*N+v, 0, true), G.add_edge(v, 2*N+u, 0, true);
        G.add_edge(N+u, 3*N+v, 0, true), G.add_edge(N+v, 3*N+u, 0, true);
        G.add_edge(u, 3*N+v, c, true), G.add_edge(v, 3*N+u, c, true);
    }

    G.dijkstra(0);
    rep2(i, 1, N-1){
        cout << G.d[3*N+i] << ' ';
    }
    cout << '\n';
}