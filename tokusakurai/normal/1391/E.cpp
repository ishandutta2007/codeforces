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
    vector<int> d;
    vector<bool> used;
    vector<int> keep;
    const int n;
    int m;

    Graph(int n) : es(n), d(n), used(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now, int pre = -1){
        d[now] = (pre == -1? 0 : d[pre]+1);
        used[now] = true;
        each(e, es[now]){
            if(!used[e.to]) dfs(e.to, now);
        }
    }

    void solve(){
        fill(all(used), false);
        dfs(0);
        vector<vector<int>> ids((n-1)/2);
        rep(i, n){
            if(d[i] >= (n-1)/2){
                fill(all(used), false);
                find_path(0, i);
                reverse(all(keep));
                cout << "PATH\n" << sz(keep) << '\n';
                rep(j, sz(keep)){
                    cout << keep[j]+1 << (j == sz(keep)-1? '\n' : ' ');
                }
                return;
            }
            ids[d[i]].eb(i);
        }
        int K = (n+1)/2;
        if(K%2 == 1) K++;
        K /= 2;
        cout << "PAIRING\n" << K << '\n';
        each(e, ids){
            rep(i, sz(e)/2){
                cout << e[2*i]+1 << ' ' << e[2*i+1]+1 << '\n';
                if(--K == 0) return;
            }
        }
    }

    bool find_path(int now, int t, int pre = -1){
        used[now] = true;
        if(now == t) {keep.eb(now); return true;}
        each(e, es[now]){
            if(used[e.to]) continue;
            if(find_path(e.to, t, now)) {keep.eb(now); return true;}
        }
        return false;
    }
};

int main(){
    int T; cin >> T;

    while(T--){
        int N, M; cin >> N >> M;

        Graph G(N);
        rep(i, M){
            int u, v; cin >> u >> v; u--, v--;
            G.add_edge(u, v);
        }

        G.solve();
    }
}