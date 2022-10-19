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
    const int n;
    int m;

    vector<ll> l, r, L, R;

    Graph(int n) : es(n), n(n), m(0), l(n), r(n), L(n, 0), R(n, 0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now, int pre = -1){
        each(e, es[now]){
            if(e.to == pre) continue;
            dfs(e.to, now);
            L[now] += max(L[e.to]+abs(l[now]-l[e.to]), R[e.to]+abs(l[now]-r[e.to]));
            R[now] += max(L[e.to]+abs(r[now]-l[e.to]), R[e.to]+abs(r[now]-r[e.to]));
        }
    }
};

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;
        Graph G(N);

        rep(i, N){
            cin >> G.l[i] >> G.r[i];
        }

        rep(i, N-1){
            int u, v; cin >> u >> v; u--, v--;
            G.add_edge(u, v);
        }

        G.dfs(0);
        cout << max(G.L[0], G.R[0]) << '\n';
    }
}