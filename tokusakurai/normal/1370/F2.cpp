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
    vector<int> d;
    const int n;
    int m;

    Graph(int n) : es(n), d(n), n(n), m(0) {}

    void add_edge(int from, int to){
        es[from].emplace_back(to, m);
        if(!directed) es[to].emplace_back(from, m);
        m++;
    }

    void dfs(int now, int pre = -1){
        if(pre == -1) d[now] = 0;
        else d[now] = d[pre]+1;
        each(e, es[now]){
            if(e.to != pre) dfs(e.to, now);
        }
    }
};

vector<int> v;

pii query(){
    cout << "? " << sz(v);
    each(e, v) cout << ' ' << e+1;
    cout << endl;
    int x, y; cin >> x >> y; x--;
    v.clear();
    return pii(x, y);
}

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        Graph G(N);
        rep(i, N-1){
            int u, v; cin >> u >> v; u--, v--;
            G.add_edge(u, v);
        }

        rep(i, N) v.eb(i);
        auto [s, r] = query();
        //cout << s << ' ' << r << endl;
        G.dfs(s);

        vector<int> id(N, -1);
        int L = (r-1)/2, R = r+1; //[L,R)
        //cout << L << ' ' << R << endl;

        while(R-L > 1){
            int M = (L+R)/2;
            rep(i, N){
                if(G.d[i] == M) v.eb(i);
            }

            if(v.empty()) {R = M; continue;}

            auto [u, d] = query();
            id[M] = u;
            (d == r? L : R) = M;
        }

        int a = id[L], b;
        G.dfs(a);

        rep(i, N){
            if(G.d[i] == r) v.eb(i);
        }

        b = query().first;

        cout << "! " << a+1 << ' ' << b+1 << endl;
        string res; cin >> res;
    }
}