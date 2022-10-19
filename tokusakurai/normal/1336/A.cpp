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
    vector<int> d, par, cnt, deg, used;
    const int n;

    Graph(int n) : n(n){
        es.resize(n), d.resize(n), deg.resize(n), par.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    void dfs(int now, int pre){
        if(pre == -1) d[now] = 0;
        else d[now] = d[pre]+1;
        deg[now] = sz(es[now]);
        if(pre != -1) deg[now]--;
        par[now] = pre;
        each(e, es[now]){
            if(e != pre) dfs(e, now);
        }
    }

    void solve(int K){
        dfs(0, -1);
        cnt.assign(n, 0), used.assign(n, 0);
        ll ans = 0;
        priority_queue<pii> que;
        rep(i, n){
            if(deg[i] == 0){
                que.emplace(d[i], i);
            }
            used[i] = d[i];
        }
        
        while(!que.empty() && K > 0){
            auto [p, i] = que.top(); que.pop();
            ans += p, K--;
            if(i != 0){
                cnt[par[i]] += cnt[i]+1;
                used[par[i]] -= cnt[i]+1;
                deg[par[i]]--;
                if(deg[par[i]] == 0){
                    que.emplace(used[par[i]], par[i]);
                }
            }
        }

        cout << ans << '\n';
    }
};

int main(){
    int N, K;
    cin >> N >> K;
    Graph G(N);
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }
    G.solve(K);
}