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

template<typename T, bool directed = false>
struct Weighted_Graph{
    struct edge{
        int to; T cost; int id;
        edge(int to, T cost, int id) : to(to), cost(cost), id(id) {}
    };

    vector<vector<edge>> es;
    vector<T> d;
    vector<int> pre_v;
    vector<int> keep;
    const T INF_T;
    const int n;
    int m;

    Weighted_Graph(int n) : es(n), d(n), pre_v(n), INF_T(numeric_limits<T>::max()/2), n(n), m(0) {}

    void add_edge(int from, int to, T cost){
        es[from].emplace_back(to, cost, m);
        if(!directed) es[to].emplace_back(from, cost, m);
        m++;
    }

    T dijkstra(int s, int t = 0){
        fill(begin(d), end(d), INF_T);
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P> > que;
        que.emplace(d[s] = 0, s);
        while(!que.empty()){
            auto [p, i] = que.top(); que.pop();
            if(p > d[i]) continue;
            for(auto &e: es[i]){
                if(d[i]+e.cost < d[e.to]){
                    pre_v[e.to] = i, que.emplace(d[e.to] = d[i]+e.cost, e.to);
                }
            }
        }
        return d[t];
    }

    vector<int> shortest_path(int s, int t){
        keep.clear();
        if(dijkstra(s, t) == INF_T) return keep;
        for(int now = t; now != s; now = pre_v[now]) keep.push_back(now);
        keep.push_back(s), reverse(begin(keep), end(keep));
        return keep;
    }
};

int main(){
    int N, M; cin >> N >> M;

    Weighted_Graph<int, true> G(51*N);

    rep(i, M){
        int u, v, w; cin >> u >> v >> w; u--, v--;

        G.add_edge(51*u, 51*v+w, w*w);
        G.add_edge(51*v, 51*u+w, w*w);

        rep2(i, 1, 50){
            G.add_edge(51*u+i, 51*v, 2*i*w+w*w);
            G.add_edge(51*v+i, 51*u, 2*i*w+w*w);
        }
    }

    G.dijkstra(0);

    rep(i, N){
        cout << (G.d[51*i] >= inf? -1 : G.d[51*i]) << (i == N-1? '\n' : ' ');
    }
}