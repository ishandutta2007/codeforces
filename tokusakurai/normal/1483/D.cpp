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
struct Table{
    vector<vector<T>> es;
    const T INF_T;
    const int n;

    inline const vector<T> &operator [] (int k) const{
        return es[k];
    }

    inline vector<T> &operator [] (int k){
        return es[k];
    }

    Table(int n) : es(n), INF_T(numeric_limits<T>::max()/2), n(n){
        for(int i = 0; i < n; i++) es[i].assign(n, INF_T);
        for(int i = 0; i < n; i++) es[i][i] = 0;
    }

    void add_edge(int from, int to, T cost = 1){
        es[from][to] = min(es[from][to], cost);
        if(!directed) es[to][from] = min(es[to][from], cost);
    }

    void warshall_floyd(){
        for(int k = 0; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(es[i][k] == INF_T || es[k][j] == INF_T) continue;
                    es[i][j] = min(es[i][j], es[i][k]+es[k][j]);
                }
            }
        }
    }
};

int main(){
    int N, M; cin >> N >> M;

    Table<ll> G(N);

    vector<vector<ll>> d(N, vector<ll>(N)), es(N, vector<ll>(N, INF));

    rep(i, M){
        int u, v; ll w; cin >> u >> v >> w; u--, v--;
        G.add_edge(u, v, w);
        es[u][v] = w, es[v][u] = w;
    }

    G.warshall_floyd();
    rep(i, N){
        rep(j, N) d[i][j] = G.es[i][j];
    }

    vector<vector<ll>> ok(N, vector<ll>(N, -INF));

    int Q; cin >> Q;

    while(Q--){
        int u, v; ll w; cin >> u >> v >> w; u--, v--;

        rep(i, N){
            ok[i][v] = max(ok[i][v], w-d[u][i]);
            ok[i][u] = max(ok[i][u], w-d[v][i]);
        }
    }

    int ans = 0;

    rep(i, N){
        rep(j, i){
            rep(k, N){
                if(es[i][j]+d[j][k] <= ok[i][k]){
                    ans++;
                    break;
                }
            }
        }
    }

    cout << ans << '\n';
}