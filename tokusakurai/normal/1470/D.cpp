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

struct Graph{
    vector<vector<int>> es;
    vector<int> col;
    vector<bool> used;
    const int n;

    Graph(int n) : n(n){
        es.resize(n);
        col.assign(n, -1), used.assign(n, false);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    void dfs(int now, int c){
        used[now] = true, col[now] = c;
        each(e, es[now]){
            if(used[e]) continue;
            dfs(e, c^1);
        }
    }

    void solve(){
        queue<int> que;
        col[0] = 1;
        que.emplace(0), used[0] = true;
        while(!que.empty()){
            int i = que.front(); que.pop();
            each(e, es[i]){
                if(used[e]) continue;
                col[e] = 0, used[e] = true;
                each(u, es[e]){
                    if(used[u]) continue;
                    col[u] = 1, used[u] = true;
                    que.emplace(u);
                }
            }
        }

        rep(i, n){
            if(!used[i]) {cout << "NO\n"; return;}
        }
        int cnt = 0;
        rep(i, n) if(col[i] == 0) cnt++;
        cout << "YES\n" << cnt << '\n';
        rep(i, n){
            if(col[i] == 0) cout << i+1 << ' ';
        }
        cout << '\n';
    }
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        Graph G(N);
        rep(i, M){
            int u, v; cin >> u >> v; u--, v--;
            G.add_edge(u, v);
        }
        G.solve();
    }
}