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
    const int n;
    int m;

    vector<int> a, col;
    vector<bool> used;

    Graph(int n) : es(n), n(n), m(0), a(n, 0), used(n, false) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++, col.eb(0);
    }

    void dfs(int now, int pre = -1, int pre_id = -1){
        used[now] = true;
        each(e, es[now]){
            if(used[e.to]) continue;
            dfs(e.to, now, e.id);
        }
        if(a[now] == 1){
            if(pre != -1) a[now] ^= 1, a[pre] ^= 1, col[pre_id] ^= 1;
        }
    }

    void solve(){
        rep(i, n){
            if(!used[i]) dfs(i);
        }
    }
};

int main(){
    int N; cin >> N;

    vector<pll> p(N), q(N);
    map<pll, int> mp;

    rep(i, N){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        ll px = d*(a+b), py = b*c, pg = gcd(px, py);
        px /= pg, py /= pg;
        mp[p[i] = pll(px, py)]++;

        ll qx = d*a, qy = b*(c+d), qg = gcd(qx, qy);
        qx /= qg, qy /= qg;
        mp[q[i] = pll(qx, qy)]++;
    }

    int n = 0;
    each(e, mp) e.second = n++;

    vector<int> u(N), v(N);
    rep(i, N) u[i] = mp[p[i]], v[i] = mp[q[i]];

    Graph G(n);
    rep(i, N){
        G.add_edge(u[i], v[i]);
        G.a[u[i]] ^= 1;
    }

    G.solve();

    vector<vector<int>> ids(n);
    rep(i, N){
        if(G.col[i] == 0) ids[u[i]].eb(i);
        else ids[v[i]].eb(i);
    }

    vector<pii> ans;
    rep(i, n){
        rep(j, sz(ids[i])/2){
            ans.eb(ids[i][2*j], ids[i][2*j+1]);
        }
    }

    cout << sz(ans) << '\n';
    each(e, ans) cout << e.first+1 << ' ' << e.second+1 << '\n';
}