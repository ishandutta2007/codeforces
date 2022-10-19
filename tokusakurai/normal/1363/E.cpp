#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Graph{
    vector<vector<int>> es;
    vector<int> b, c;
    vector<ll> a, m;
    ll ans;
    const int n;

    Graph(int n) : n(n){
        es.resize(n);
        a.resize(n), b.resize(n), c.resize(n), m.resize(n);
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    void dfs1(int now, int pre){
        m[now] = a[now];
        if(pre != -1) chmin(m[now], m[pre]);
        for(auto &e: es[now]){
            if(e != pre) dfs1(e, now);
        }
    }

    pll dfs2(int now, int pre){
        ll p = 0, q = 0;
        if(b[now] != c[now]){
            if(b[now] == 0) p++;
            else q++;
        }
        for(auto &e: es[now]){
            if(e == pre) continue;
            ll x, y;
            tie(x, y) = dfs2(e, now);
            p += x, q += y;
        }
        ll k = min(p, q);
        ans += m[now]*k*2;
        return pll(p-k, q-k);
    }

    ll solve(){
        dfs1(0, -1);
        ans = 0;
        pll p = dfs2(0, -1);
        if(p != pll(0, 0)) return -1;
        return ans;
    }
};

int main(){
    int N;
    cin >> N;
    Graph G(N);
    rep(i, N){
        cin >> G.a[i] >> G.b[i] >> G.c[i];
    }
    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }
    cout << G.solve() << endl;
}