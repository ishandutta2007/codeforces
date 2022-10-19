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

template<bool directed = false>
struct Graph{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;

    vector<int> vs; //DFS
    vector<int> ls, rs; //i[ls[i],rs[i])vs[ls[i]] = i
    Binary_Indexed_Tree<int> b1, b2;

    Graph(int n) : es(n), n(n), m(0), ls(n), rs(n), b1(vector<int>(n, 0)), b2(vector<int>(n+1, 0)) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void euler_tour(int now, int pre = -1){
        ls[now] = vs.size(), vs.push_back(now);
        for(auto &e: es[now]){
            if(e.to != pre) euler_tour(e.to, now);
        }
        rs[now] = vs.size();
    }

    int query(int k){
        if(b1.query(ls[k], rs[k]) > 0) return -2;
        int r = b2.query(0, ls[k]+1);
        return r-1;
    }

    void insert(int k){
        b1.add(ls[k], 1);
        b2.add(ls[k], k+1), b2.add(rs[k], -k-1);
    }

    void erase(int k){
        b1.add(ls[k], -1);
        b2.add(ls[k], -k-1), b2.add(rs[k], k+1);
    }
};

template<bool directed = false>
struct Graph2{
    struct edge{
        int to, id;
        edge(int to, int id) : to(to), id(id) {}
    };

    vector<vector<edge>> es;
    const int n;
    int m;
    int cnt, ans;
    Graph<true> G;

    Graph2(int n, Graph<true> G) : es(n), n(n), m(0), cnt(0), ans(0), G(G) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now){
        int k = G.query(now);
        if(k == -1){
            cnt++;
            G.insert(now);
        }
        else if(k >= 0){
            G.erase(k), G.insert(now);
        }
        chmax(ans, cnt);

        each(e, es[now]) dfs(e.to);

        if(k == -1){
            cnt--;
            G.erase(now);
        }
        else if(k >= 0){
            G.insert(k), G.erase(now);
        }
    }
};

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        Graph<true> G(N);
        vector<int> par(N-1);
        rep(i, N-1){
            cin >> par[i]; par[i]--;
        }
    
        rep(i, N-1){
            int p; cin >> p; p--;
            G.add_edge(p, i+1);
        }
        G.euler_tour(0);

        Graph2<true> G2(N, G);

        rep(i, N-1){
            G2.add_edge(par[i], i+1);
        }

        G2.dfs(0);
        cout << G2.ans << '\n';
    }
}