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
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct Union_Find_Tree{
    vector<int> par, rank, num;
    const int n;
    
    Union_Find_Tree(int n) : n(n){
        par.assign(n, -1), rank.assign(n, 0), num.assign(n, 1);
    }
    
    int root(int x){
        if(par[x] < 0 || par[x] == x) return x;
        return par[x] = root(par[x]);
    }
    
    bool unite(int x, int y){
        x = root(x), y = root(y);
        if(x == y) return false;
        if(rank[x] < rank[y]) swap(x, y);
        if(rank[x] == rank[y]) rank[x]++;
        par[y] = x, num[x] += num[y];
        return true;
    }
    
    int size(int x) {return num[root(x)];}
    
    bool same(int x, int y) {return root(x) == root(y);}
    
    void clear(){
        fill(all(par), -1), fill(all(rank), 0), fill(all(num), 1);
    }
};

struct edge{
    ll cost;
    int c, v;
    edge(ll cost, int c, int v) : cost(cost), c(c), v(v) {}
};

int main(){
    int M, N;
    cin >> M >> N;
    ll a[M], b[N];
    rep(i, M) cin >> a[i];
    rep(i, N) cin >> b[i];
    vector<edge> es;
    rep(i, M){
        int K; cin >> K;
        while(K--){
            int v; cin >> v; v--;
            es.eb(a[i]+b[v], i, v);
        }
    }
    int root[M];
    fill(root, root+M, -1);
    sort(all(es), [&](const edge &e1, const edge&e2){
        return e1.cost > e2.cost;
    });
    ll ans = 0;
    Union_Find_Tree uf(N);
    for(auto &e: es){
        if(root[e.c] == -1) {root[e.c] = e.v; continue;}
        if(!uf.unite(e.v, root[e.c])) ans += e.cost;
    }
    cout << ans << endl;
}