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
    int N, M, Q; cin >> N >> M >> Q;

    int R = 400;

    vector<int> ok(N, 0);
    int K; cin >> K;
    rep(i, K){
        int u; cin >> u; u--;
        ok[u] = 1;
    }

    vector<set<int>> es(N);
    vector<int> deg(N, -1), id(N, -1);
    vector<int> vs;
    vector<vector<bool>> ok2(N, vector<bool>(1000, false));

    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        es[u].emplace(v);
            es[v].emplace(u);

            if(deg[u] >= 0){
                deg[u] += ok[v];
                ok2[v][id[u]] = true;
            }
            if(deg[v] >= 0){
                deg[v] += ok[u];
                ok2[u][id[v]] = true;
            }

            if(sz(es[u]) >= R && deg[u] == -1){
                deg[u] = 0, id[u] = sz(vs);
                vs.eb(u);
                each(w, es[u]){
                    deg[u] += ok[w];
                    ok2[w][id[u]] = true;
                }
            }
            if(sz(es[v]) >= R && deg[v] == -1){
                deg[v] = 0, id[v] = sz(vs);
                vs.eb(v);
                each(w, es[v]){
                    deg[v] += ok[w];
                    ok2[w][id[v]] = true;
                }
            }
    }
    /*
    rep(i, N){
        each(e, vs){
            if(es[i].count(e)){
                deg[e] += ok[i];
                ok2[i][id[e]] = true;
            }
        }
    }
    */
    while(Q--){
        char c; int u, v; cin >> c >> u; u--;

        if(c == 'O'){
            ok[u] = 1;
            each(e, vs){
                if(ok2[u][id[e]]) deg[e]++;
            }
        }
        if(c == 'F'){
            ok[u] = 0;
            each(e, vs){
                if(ok2[u][id[e]]) deg[e]--;
            }
        }
        if(c == 'A'){
            cin >> v; v--;
            es[u].emplace(v);
            es[v].emplace(u);

            if(deg[u] >= 0){
                deg[u] += ok[v];
                ok2[v][id[u]] = true;
            }
            if(deg[v] >= 0){
                deg[v] += ok[u];
                ok2[u][id[v]] = true;
            }

            if(sz(es[u]) >= R && deg[u] == -1){
                deg[u] = 0, id[u] = sz(vs);
                vs.eb(u);
                each(w, es[u]){
                    deg[u] += ok[w];
                    ok2[w][id[u]] = true;
                }
            }
            if(sz(es[v]) >= R && deg[v] == -1){
                deg[v] = 0, id[v] = sz(vs);
                vs.eb(v);
                each(w, es[v]){
                    deg[v] += ok[w];
                    ok2[w][id[v]] = true;
                }
            }
        }
        if(c == 'D'){
            cin >> v; v--;
            es[u].erase(v);
            es[v].erase(u);

            if(deg[u] >= 0){
                deg[u] -= ok[v];
                ok2[v][id[u]] = false;
            }
            if(deg[v] >= 0){
                deg[v] -= ok[u];
                ok2[u][id[v]] = false;
            }
        }
        if(c == 'C'){
            if(deg[u] >= 0) cout << deg[u] << '\n';
            else{
                int ans = 0;
                each(e, es[u]){
                    if(ok[e]) ans++;
                }
                cout << ans << '\n';
            }
        }
    }
}