#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
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
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

template<typename T>
struct Weighted_Graph{
    struct edge{
        int to; T cost;
        edge(int to, T cost) : to(to), cost(cost) {}
    };

    vector<vector<edge>> es;
    const T INF_T;
    const int n;

    Weighted_Graph(int n) : INF_T(numeric_limits<T>::max()), n(n){
        es.resize(n);
    }

    void add_edge(int from, int to, T cost, bool directed = false){
        es[from].eb(to, cost);
        if(!directed) es[to].eb(from, cost);
    }

    T dijkstra(int s, int t){
        vector<T> d(n, INF_T);
        using P = pair<T, int>;
        priority_queue<P, vector<P>, greater<P>> que;
        que.emplace(d[s] = 0, s);
        while(!que.empty()){
            T p; int i;
            tie(p, i) = que.top(); que.pop();
            if(p > d[i]) continue;
            for(auto &e: es[i]){
                if(chmin(d[e.to], d[i]+e.cost)) que.emplace(d[e.to], e.to);
            }
        }
        return d[t];
    }
};

struct node{
    ll x, y; int id;
    node(ll x, ll y, int id) : x(x), y(y), id(id) {}
};

int main(){
    ll N; int M;
    cin >> N >> M;
    Weighted_Graph<ll> G(M+2);
    int s = M, t = M+1;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<node> nodes;
    rep(i, M){
        ll x, y;
        cin >> x >> y;
        nodes.eb(x, y, i);
    }
    for(auto &e: nodes){
        G.add_edge(s, e.id, min(abs(e.x-sx), abs(e.y-sy)));
        G.add_edge(t, e.id, abs(e.x-tx)+abs(e.y-ty));
    }
    sort(all(nodes), [](node a, node b){
        return a.x < b.x;
    });
    rep(i, M-1){
        node &a = nodes[i], &b = nodes[i+1];
        G.add_edge(a.id, b.id, b.x-a.x);
    }
    sort(all(nodes), [](node a, node b){
        return a.y < b.y;
    });
    rep(i, M-1){
        node &a = nodes[i], &b = nodes[i+1];
        G.add_edge(a.id, b.id, b.y-a.y);
    }
    cout << min(abs(sx-tx)+abs(sy-ty), G.dijkstra(s, t)) << endl;
}