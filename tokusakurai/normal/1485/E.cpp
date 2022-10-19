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
    vector<ll> a;
    vector<int> d;
    const int n;
    int m;

    Graph(int n) : es(n), n(n), a(n), d(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now, int pre = -1){
        d[now] = (pre == -1? 0 : d[pre]+1);
        each(e, es[now]){
            if(e.to == pre) continue;
            dfs(e.to, now);
        }
    }

    void solve(){
        rep2(i, 1, n-1){
            int p; cin >> p; p--;
            add_edge(p, i);
        }
        rep2(i, 1, n-1) cin >> a[i];

        dfs(0);
        int D = *max_element(all(d));

        vector<vector<int>> ids(D+1);
        rep(i, n){
            ids[d[i]].eb(i);
        }

        vector<ll> dp(n, 0);

        rep(i, D){
            ll M1 = 0, m1 = INF;
            each(e, ids[i+1]){
                chmax(M1, a[e]), chmin(m1, a[e]);
            }

            ll M2 = 0, m2 = -INF;
            each(e, ids[i]){
                each(u, es[e]){
                    if(d[u.to] != i+1) continue;
                    chmax(dp[u.to], dp[e]+M1-a[u.to]), chmax(dp[u.to], dp[e]+a[u.to]-m1);
                    chmax(M2, dp[e]+a[u.to]), chmax(m2, dp[e]-a[u.to]);
                }
            }

            each(e, ids[i+1]){
                chmax(dp[e], M2-a[e]), chmax(dp[e], m2+a[e]);
            }
        }

        ll ans = 0;
        each(e, ids[D]) chmax(ans, dp[e]);

        cout << ans << '\n';
    }
};

int main(){
    int T; cin  >> T;

    while(T--){
        int N; cin >> N;

        Graph G(N);
        G.solve();
    }
}