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

struct Union_Find_Tree{
    vector<int> data;
    const int n;
    
    Union_Find_Tree(int n) : data(n, -1), n(n) {}
    
    int root(int x){
        if(data[x] < 0) return x;
        return data[x] = root(data[x]);
    }

    int operator [] (int i) {return root(i);}
    
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y], data[y] = x;
        return true;
    }
    
    int size(int x) {return -data[root(x)];}
    
    bool same(int x, int y) {return root(x) == root(y);}
    
    void clear() {fill(begin(data), end(data), -1);}
};

int main(){
    int N, M; ll x; cin >> N >> M >> x;

    vector<ll> a(N);
    rep(i, N) cin >> a[i];

    vector<int> par(N);
    vector<vector<pii>> es(N);
    //vector<vector<int>> chi(N);
    priority_queue<pli> que;

    rep(i, N){
        par[i] = i;
        //chi[i].eb(i);
        que.emplace(a[i], i);
    }

    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        es[u].eb(v, i), es[v].eb(u, i);
    }

    if(accumulate(all(a), 0LL) < x*(N-1)) {cout << "NO\n"; return 0;}

    vector<int> ans;
    Union_Find_Tree uf(N);
    
    while(!que.empty()){
        ll p; int u;
        tie(p, u) = que.top(); que.pop();

        if(u != par[uf[u]] || a[u] != p) continue;
        
        while(!es[u].empty() && uf.same(u, par[uf[es[u].back().first]])){
            es[u].pop_back();
        }

        if(es[u].empty()) break;
        
        int v = par[uf[es[u].back().first]];
        //cout << u << ' ' << v << endl;
        ans.eb(es[u].back().second);
        es[u].pop_back();

        if(sz(es[u]) < sz(es[v])) swap(u, v);
        que.emplace(a[u] += a[v]-x, u);
        
        uf.unite(u, v);
        par[uf[u]] = u;

        each(e, es[v]) es[u].eb(e);
    }
    
    cout << "YES\n";
    each(e, ans) cout << e+1 << '\n';
}