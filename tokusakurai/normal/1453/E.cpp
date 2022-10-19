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
    vector<int> d, dp;
    const int n;

    Graph(int n) : n(n){
        es.resize(n), d.resize(n), dp.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    void dfs1(int now, int pre){
        if(pre == -1) d[now] = 0;
        else d[now] = d[pre]+1;
        each(e, es[now]){
            if(e == pre) continue;
            dfs1(e, now);
        }
    }

    void dfs2(int now, int pre, int k){
        if(pre != -1 && sz(es[now]) == 1) {dp[now] = d[now]; return;}
        vector<int> keep;
        each(e, es[now]){
            if(e == pre) continue;
            dfs2(e, now, k);
            if(dp[e] == -1) {dp[now] = -1; return;}
            keep.eb(dp[e]);
        }
        sort(all(keep));
        if(pre != -1){
            if(keep.back() >= d[now]+k) {dp[now] = -1; return;}
            dp[now] = keep.front(); return;
        }
        else{
            if(keep.back() > k) {dp[now] = -1; return;}
            if(keep.back() < k) {dp[now] = keep.front(); return;}
            if(sz(keep) == 1 || keep[sz(keep)-2] < k) {dp[now] = keep.front(); return;}
            dp[now] = -1; return;
        }
    }

    bool judge(int k){
        dfs2(0, -1, k);
        if(dp[0] == -1) return false;
        return true;
    }
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int N;
        cin >> N;
        Graph G(N);
        rep(i, N-1){
            int u, v; cin >> u >> v; u--, v--;
            G.add_edge(u, v);
        }
        G.dfs1(0, -1);
        int l = 0, r = N;
        while(r-l > 1){
            int m = (l+r)/2;
            if(G.judge(m)) r = m;
            else l = m;
        }
        cout << r << '\n';
    }
}