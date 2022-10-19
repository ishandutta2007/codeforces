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

    vector<int> vs, ls, rs, d;

    Graph(int n) : es(n), n(n), m(0), ls(n), rs(n), d(n) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now, int pre = -1){
        ls[now] = sz(vs), vs.eb(now);
        if(pre == -1) d[now] = 0;
        else d[now] = d[pre]+1;
        each(e, es[now]){
            if(e.to == pre) continue;
            dfs(e.to, now);
        }
        rs[now] = sz(vs);
    }
};

template<typename T>
struct Binary_Indexed_Tree{
    vector<T> bit;
    const int n;
    
    Binary_Indexed_Tree(const vector<T> &v) : n((int)v.size()){
        bit.resize(n+1);
        copy(begin(v), end(v), begin(bit)+1);
        for(int a = 2; a <= n; a <<= 1){
            for(int b = a; b <= n; b += a){
                bit[b] += bit[b-a/2];
            }
        }
    }
    
    void add(int i, const T &x){
        for(i++; i <= n; i += (i & -i)) bit[i] += x;
    }

    void change(int i, const T&x){
        add(i, x-query(i, i+1));
    }
    
    T sum(int i) const{
        T ret = 0;
        for(; i > 0; i -= (i & -i)) ret += bit[i];
        return ret;
    }
    
    T query(int l, int r) const{
        return sum(r) - sum(l);
    }

    T operator [] (int i) const {return query(i, i+1);}

    int lower_bound(T x) const{
        int ret = 0;
        for(int k = 31-__builtin_clz(n); k >= 0; k--){
            if(ret+(1<<k) <= n && bit[ret+(1<<k)] < x) x -= bit[ret += (1<<k)]; 
        }
        return ret;
    }

    int upper_bound(T x) const {return lower_bound(x+1);}
};

int main(){
    int N, Q; cin >> N >> Q;

    vector<int> a(N, 0);
    rep(i, N) cin >> a[i];

    Binary_Indexed_Tree<int> bit(vector<int>(N+1, 0));

    Graph G(N);

    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    G.dfs(0);

    while(Q--){
        int t, u; cin >> t >> u; u--;
        if(t == 1){
            int x; cin >> x;
            if(G.d[u]&1) x = -x;
            bit.add(G.ls[u], x), bit.add(G.rs[u], -x);
        }
        else{
            int ans = bit.query(0, G.ls[u]+1);
            if(G.d[u]&1) ans = -ans;
            cout << a[u]+ans << '\n';
        }
    }
}