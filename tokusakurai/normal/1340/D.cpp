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

vector<pii> ans;

struct Graph{
    vector<vector<int>> es;
    const int n;

    Graph(int n) : n(n){
        es.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    void dfs(int now, int pre, int t){
        ans.eb(now+1, t);
        int deg = sz(es[now]);
        bool flag = (pre != -1);
        if(flag && t >= deg){
            ans.eb(now+1, (t -= deg));
            flag = false;
        }

        each(e, es[now]){
            if(e == pre) continue;
            dfs(e, now, t+1);
            ans.eb(now+1, ++t);
            if(flag && t >= deg){
                ans.eb(now+1, (t -= deg));
                flag = false;
            }
        }
    }
};

int main(){
    int N;
    cin >> N;
    Graph G(N);
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    G.dfs(0, -1, 0);
    cout << sz(ans) << '\n';
    each(e, ans) cout << e.first << ' ' << e.second << '\n';
}