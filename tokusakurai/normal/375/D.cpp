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

    vector<int> vs; //DFS
    vector<int> ls, rs; //i[ls[i],rs[i])vs[ls[i]] = i

    Graph(int n) : es(n), n(n), m(0), ls(n), rs(n) {}

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
};

struct query{
    int l, r, K, id;
    query(int l, int r, int K, int id) : l(l), r(r), K(K), id(id) {}
};

const int MAX = 100000;
 
template<typename T, typename Q> //TQ
struct Mo{
    vector<T> a;
    const int n;
    int l, r;
    Q ans;

    vector<int> cnt1, cnt2;
 
    Mo(vector<T> a) : a(a), n(a.size()), l(0), r(0), ans(0){
        cnt1.assign(MAX, 0);
        cnt2.assign(MAX+1, 0);
    }
 
    void insert(int x){
        int c = a[x];
        cnt2[++cnt1[c]]++;
    }

    void insert_left(int x){
        insert(x);
    }

    void insert_right(int x){
        insert(x);
    }

    void erase(int x){
        int c = a[x];
        cnt2[cnt1[c]--]--;
    }

    void erase_left(int x){
        erase(x);
    }

    void erase_right(int x){
        erase(x);
    }

    vector<Q> solve(int bucket_size, vector<query> qs){
        vector<Q> ret(qs.size());
        sort(begin(qs), end(qs), [&](query a, query b){
            int A = (a.l)/bucket_size, B = (b.l)/bucket_size;
            if(A != B) return A < B;
            if(A%2 == 0) return a.r < b.r;
            return a.r > b.r;
        });
        for(auto &e: qs){
            while(e.l < l) insert(--l);
            while(r < e.r) insert(r++);
            while(l < e.l) erase(l++);
            while(e.r < r) erase(--r);
            ret[e.id] = cnt2[e.K];
        }
        return ret;
    }
};

int main(){
    int N, Q; cin >> N >> Q;

    vector<int> c(N);
    rep(i, N) {cin >> c[i]; c[i]--;}

    Graph G(N);

    rep(i, N-1){
        int u, v; cin >> u >> v; u--, v--;
        G.add_edge(u, v);
    }

    G.euler_tour(0);

    vector<int> a(N);
    rep(i, N) a[G.ls[i]] = c[i];

    Mo<int, int> mo(a);

    vector<query> qs;

    rep(i, Q){
        int u, K; cin >> u >> K; u--;
        qs.eb(G.ls[u], G.rs[u], K, i);
    }

    vector<int> ans = mo.solve(300, qs);

    rep(i, Q) cout << ans[i] << '\n';
}