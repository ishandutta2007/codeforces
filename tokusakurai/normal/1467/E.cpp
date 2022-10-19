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

template<typename T>
struct Binary_Indexed_Tree{
    vector<T> bit;
    const int n;
    
    Binary_Indexed_Tree(const vector<T> &v) : n(sz(v)){
        bit.resize(n+1);
        copy(all(v), bit.begin()+1);
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

struct Graph{
    vector<vector<int>> es;
    vector<int> c, par, d, L, R, a, b, col;
    int K;
    bool flag;
    const int n;

    Graph(int n) : n(n){
        es.resize(n), c.resize(n), par.resize(n), d.resize(n);
        L.resize(n), R.resize(n), a.assign(n, 0), b.assign(n, 0), col.assign(n, 0);
        K = 0;
        flag = false;
    }

    void add_edge(int from, int to, bool directed = false){
        es[from].pb(to);
        if(!directed) es[to].pb(from);
    }

    void dfs1(int now, int pre){
        par[now] = pre;
        L[now] = K++;
        if(pre == -1) d[now] = 0;
        else d[now] = d[pre]+1;
        each(e, es[now]){
            if(e != pre) dfs1(e, now);
        }
        R[now] = K++;
    }

    int dfs2(int now, int pre){
        int ret = a[now], cnt = 0;
        each(e, es[now]){
            if(e == pre) continue;
            int tmp = dfs2(e, now);
            if(tmp > 0) cnt++;
            ret += tmp;
        }
        if(cnt >= 2) flag = true;
        return ret;
    }

    void dfs3(int now){
        col[now] = 1;
        each(e, es[now]){
            if(e == par[now]) continue;
            dfs3(e);
        }
    }

    void dfs4(int now, bool ng){
        if(b[now]) ng = true;
        if(ng) col[now] = 0;
        each(e, es[now]){
            if(e == par[now]) continue;
            dfs4(e, ng);
        }
    }
};

int main(){
    int N; cin >> N;

    Graph G(N);

    map<int, vector<int>> mp;
    rep(i, N){
        cin >> G.c[i];
        mp[G.c[i]].eb(i);
    }

    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    G.dfs1(0, -1);
    Binary_Indexed_Tree<int> bit(vector<int>(2*N, 0));
    
    each(e, mp){
        if(sz(e.second) == 1) continue;
        each(u, e.second){
            bit.add(G.L[u], 1), bit.add(G.R[u], 1);
        }

        each(u, e.second){
            if(bit.query(G.L[u]+1, G.R[u]) == 0){
                G.b[u] = 1;
                continue;
            }

            each(v, G.es[u]){
                if(v == G.par[u]) continue;
                int x = bit.query(G.L[v], G.R[v]+1);
                if(x == 0) continue;
                if(x != 2*sz(e.second)-2) {cout << "0\n"; return 0;}
                G.a[v] = 1;
            }
        }

        each(u, e.second){
            bit.add(G.L[u], -1), bit.add(G.R[u], -1);
        }
    }

    G.a[0] = 1;

    G.dfs2(0, -1);
    if(G.flag) {cout << "0\n"; return 0;}

    int D = 0, P = 0;
    rep(i, N){
        if(G.a[i]){
            if(chmax(D, G.d[i])) P = i;
        }
    }
    G.dfs3(P), G.dfs4(0, false);

    cout << accumulate(all(G.col), 0) << '\n';
}