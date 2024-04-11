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

    vector<vector<edge>> es, es2;
    const T INF_T;
    const int n;
    int m, k;

    vector<T> d;
    vector<int> pre_v;
    vector<T> L, R, C;

    Weighted_Graph(int n) : es(n), es2(n), INF_T(numeric_limits<T>::max()/2), n(n), m(0), k(0), d(n), pre_v(n) {}

    void add_edge(int from, int to, T cost){
        es[from].emplace_back(to, cost, m);
        if(!directed) es[to].emplace_back(from, cost, m);
        m++;
    }

    void add_edge2(int from, int to, T l, T r){
        es2[from].emplace_back(to, 0, k);
        if(!directed) es2[to].emplace_back(from, 0, k);
        L.eb(l), R.eb(r), C.eb(0);
        k++;
    }

    int greedy(int s1, int s2, int t){
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P>> que1, que2;
        vector<T> d1(n, INF_T), d2(n, INF_T);
        que1.emplace(d1[s1] = 0, s1), que2.emplace(d2[s2] = 0, s2);

        while(!que1.empty() && !que2.empty()){
            if(que2.empty() || que1.top().first <= que2.top().first){
                auto [p, i] = que1.top(); que1.pop();
                if(p > d1[i]) continue;
                each(e, es2[i]){
                    if(C[e.id] == 0) C[e.id] = L[e.id];
                    e.cost = C[e.id];
                    if(chmin(d1[e.to], d1[i]+e.cost)) que1.emplace(d1[e.to], e.to);
                }
                each(e, es[i]){
                    if(chmin(d1[e.to], d1[i]+e.cost)) que1.emplace(d1[e.to], e.to);
                }
            }
            else{
                auto [p, i] = que2.top(); que2.pop();
                if(p > d2[i]) continue;
                each(e, es2[i]){
                    if(C[e.id] == 0) C[e.id] = R[e.id];
                    e.cost = C[e.id];
                    if(chmin(d2[e.to], d2[i]+e.cost)) que2.emplace(d2[e.to], e.to);
                }
                each(e, es[i]){
                    if(chmin(d2[e.to], d2[i]+e.cost)) que2.emplace(d2[e.to], e.to);
                }
            }
        }

        return (d1[t] < d2[t]? 1 : d1[t] > d2[t]? -1 : 0);
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
            for(auto &e: es2[i]){
                if(d[i]+e.cost < d[e.to]){
                    pre_v[e.to] = i, que.emplace(d[e.to] = d[i]+e.cost, e.to);
                }
            }
        }
        return d[t];
    }

    vector<int> shortest_path(int s, int t){
        if(dijkstra(s, t) == INF_T) return {};
        vector<int> ret;
        for(int now = t; now != s; now = pre_v[now]) ret.push_back(now);
        ret.push_back(s), reverse(begin(ret), end(ret));
        return ret;
    }

    void solve(int s1, int s2, int t){
        int res = greedy(s1, s2, t);
        if(res == -1) cout << "LOSE\n";
        else{
            cout << (res == 0? "DRAW\n" : "WIN\n");
            rep(i, k){
                cout << (C[i] == 0? L[i] : C[i]) << (i == k-1? '\n' : ' ');
            }
        }
    }
};

int main(){
    int N, M, K; cin >> N >> M >> K;
    int s1, s2, t; cin >> s1 >> s2 >> t; s1--, s2--, t--;

    Weighted_Graph<ll, true> G(N);

    rep(i, M){
        int u, v; ll c; cin >> u >> v >> c; u--, v--;
        G.add_edge(u, v, c);
    }

    rep(i, K){
        int u, v; ll l, r; cin >> u >> v >> l >> r; u--, v--;
        G.add_edge2(u, v, l, r);
    }

    G.solve(s1, s2, t);
}