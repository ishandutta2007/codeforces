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
    vector<ll> a, c, s;
    ll ans, S;
    const int n;
    int m;

    Graph(int n) : es(n), a(n), c(n), s(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now, int pre = -1){
        if(pre != -1 && sz(es[now]) == 1){
            c[now] = a[now], s[now] = 1, ans += a[now];
            return;
        }

        ll L = 1, deg = 0;

        each(e, es[now]){
            if(e.to == pre) continue;

            dfs(e.to, now);

            if(s[e.to] == 0) L = 0;
            else{
                ll G = gcd(L, s[e.to]);
                if(L/G > S/s[e.to]) L = 0;
                else L *= s[e.to]/G;
            }

            deg++;
        }

        if(L == 0) {c[now] = 0, s[now] = 0; return;}

        c[now] = INF;

        each(e, es[now]){
            if(e.to == pre) continue;

            chmin(c[now], c[e.to]-c[e.to]%L);
        }

        c[now] *= deg, s[now] = L*deg;
    }

    void solve(){
        ans = 0, S = accumulate(all(a), 0LL);
        dfs(0);
        cout << ans-c[0] << '\n';
    }
};

int main(){
    int N; cin >> N;

    Graph G(N);

    rep(i, N) cin >> G.a[i];

    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    G.solve();
}