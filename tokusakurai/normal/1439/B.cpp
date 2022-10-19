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

int main(){
    int T;
    cin >> T;
    while(T--){
        ll N, M, K;
        cin >> N >> M >> K;
        vector<int> es[N];
        rep(i, M){
            int u, v; cin >> u >> v; u--, v--;
            es[u].eb(v), es[v].eb(u);
        }

        if(K*(K-1) > 2*M) {cout << -1 << '\n'; continue;}

        priority_queue<pii, vector<pii>, greater<pii>> que;
        vector<int> cnt(N);
        vector<vector<int>> check(N), par(N);
        rep(i, N){
            que.emplace(cnt[i] = sz(es[i]), i);
        }

        bool fin = false;

        while(!que.empty()){
            auto [p, i] = que.top(); que.pop();
            if(cnt[i] == -1) continue;
            if(p == K-1){
                each(e, es[i]){
                    if(cnt[e] >= 0) check[i].eb(e), par[e].eb(i);
                }
            }
            if(p >= K){
                vector<int> ans;
                rep(i, N){
                    if(cnt[i] >= 0) ans.eb(i);
                }
                fin = true;
                cout << 1 << ' ' << sz(ans) << '\n';
                each(e, ans) cout << e+1 << ' '; cout << '\n';
                break;
            }
            if(p <= K-1){
                cnt[i] = -1;
                each(e, es[i]){
                    if(cnt[e] >= 0) que.emplace(--cnt[e], e);
                }
            }
        }

        if(fin) continue;

        vector<bool> g(N, false), ok(N, true);
        rep(i, N){
            each(e, es[i]) g[e] = true;
            g[i] = true;
            each(e, par[i]){
                each(u, check[e]){
                    if(!g[u]) ok[e] = false;
                }
            }
            each(e, es[i]) g[e] = false;
            g[i] = false;
        }

        rep(i, N){
            if(sz(check[i]) == K-1 && ok[i]){
                fin = true;
                cout << 2 << '\n';
                each(e, check[i]) cout << e+1 << ' ';
                cout << i+1 << '\n';
                break;
            }
        }

        if(!fin) cout << -1 << '\n';
    }
}