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

template<typename F>
struct Max_Flow{
    struct edge{
        int to; F cap; int rev;
        edge(int to, F cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    vector<vector<edge>> es;
    vector<bool> used;
    const F INF_F;
    const int n;

    Max_Flow(int n) : es(n), used(n), INF_F(numeric_limits<F>::max()), n(n) {}

    void add_edge(int from, int to, F cap, bool directed = true){
        es[from].emplace_back(to, cap, (int)es[to].size());
        es[to].emplace_back(from, directed? 0 : cap, (int)es[from].size()-1);
    }

    F _dfs(int now, int t, F flow){
        if(now == t) return flow;
        used[now] = true;
        for(auto &e: es[now]){
            if(!used[e.to] && e.cap > 0){
                F f = _dfs(e.to, t, min(flow, e.cap));
                if(f > 0){
                    e.cap -= f, es[e.to][e.rev].cap += f;
                    return f;
                }
            }
        }
        return 0;
    }

    F max_flow(int s, int t){
        F flow = 0;
        for(;;){
            fill(begin(used), end(used), false);
            F f = _dfs(s, t, INF_F);
            if(f == 0) return flow;
            flow += f;
        }
    }

    void clear(){
        rep(i, n) es[i].clear();
    }
};

int main(){
    int N, M, K; cin >> N >> M >> K;

    vector<vector<int>> es(N);
    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        es[u].eb(N+v);
    }

    vector<int> id(N+1, 0);

    Max_Flow<int> G(2*N+2);
    int s = 2*N, t = 2*N+1;

    rep(i, N){
        G.add_edge(s, i, 1);
        G.add_edge(N+i, t, 1);

        each(e, es[i]){
            G.add_edge(i, e, 1);
        }
    }

    int F = N-G.max_flow(s, t);
    rep2(i, 0, F) id[i] = -1;
    vector<bool> used(2*N, false);
    
    rep2(i, F+1, N){
        rep(j, 2*N){
            if(used[j]) continue;
            G.clear();
            used[j] = true;

            rep(k, N){
                G.add_edge(s, k, 1);
                G.add_edge(N+k, t, 1);
                if(used[k]) continue;
                each(e, es[k]){
                    if(!used[e]) G.add_edge(k, e, 1);
                }
            }

            if(N-G.max_flow(s, t) == i){
                id[i] = j;
                break;
            }

            used[j] = false;
        }
    }

    vector<vector<ll>> dp(K+1, vector<ll>(N+1, -INF));
    vector<vector<int>> pre(K+1, vector<int>(N+1, -1));
    dp[0][0] = 0;

    rep(i, K){
        ll x, y; cin >> x >> y;

        rep(j, N+1){
            ll tmp = x;
            rep2(k, j, N){
                if(k >= i+2){
                    if(chmax(dp[i+1][k], dp[i][j]+tmp)){
                        pre[i+1][k] = j;
                    }
                }
                if(k < N && id[k+1] != -1){
                    tmp -= y, chmax(tmp, 0LL);
                }
            }
        }
    }

    int pj = max_element(all(dp[K]))-begin(dp[K]);
    vector<int> ans;

    rep3(i, K, 1){
        ans.eb(0);
        int nj = pre[i][pj];

        rep3(j, pj, nj+1){
            if(id[j] == -1) continue;
            if(id[j] < N) ans.eb(id[j]+1);
            else ans.eb(N-1-id[j]);
        }

        pj = nj;
    }

    reverse(all(ans));
    int n = sz(ans);
    cout << n << '\n';
    rep(i, n) cout << ans[i] << (i == n-1? '\n' : ' ');
}