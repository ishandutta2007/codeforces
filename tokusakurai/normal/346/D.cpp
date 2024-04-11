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

    vector<vector<edge>> es, rs;
    const int n;
    int m;

    vector<int> deg;

    Graph(int n) : es(n), rs(n), n(n), m(0), deg(n, 0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        rs[to].emplace_back(from, m);
        m++, deg[from]++;
    }

    void solve(int s, int t){
        vector<int> d(n, inf);
        priority_queue<pii, vector<pii>, greater<pii>> que;
        que.emplace(d[t] = 0, t);

        while(!que.empty()){
            auto [p, i] = que.top(); que.pop();
            if(d[i] < p) continue;
            each(e, rs[i]){
                deg[e.to]--;
                if(chmin(d[e.to], d[i]+(deg[e.to] == 0? 0 : 1))){
                    que.emplace(d[e.to], e.to);
                }
            }
        }

        //rep(i, n) cout << d[i] << ' '; cout << '\n';

        cout << (d[s] == inf? -1 : d[s]) << '\n';
    }
};

int main(){
    int N, M; cin >> N >> M;

    Graph<true> G(N);

    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    int s, t; cin >> s >> t; s--, t--;

    G.solve(s, t);
}