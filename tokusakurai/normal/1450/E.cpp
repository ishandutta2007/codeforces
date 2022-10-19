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
    
    Union_Find_Tree(int n) : n(n){
        data.assign(n, -1);
    }
    
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
    
    void clear() {fill(all(data), -1);}
};

template<typename T>
struct List{
    vector<vector<T>> es;
    const T INF_T;
    const int n;

    inline const vector<T> &operator [] (int k) const{
        return es[k];
    }

    inline vector<T> &operator [] (int k){
        return es[k];
    }

    List(int n) : INF_T(numeric_limits<T>::max()/2), n(n){
        es.resize(n);
        rep(i, n) es[i].assign(n, INF_T);
        rep(i, n) es[i][i] = 0;
    }

    void add_edge(int from, int to, T cost = 1, bool directed = false){
        es[from][to] = cost;
        if(!directed) es[to][from] = cost;
    }

    void warshall_floyd(){
        rep(k, n){
            rep(i, n){
                rep(j, n){
                    if(es[i][k] == INF_T || es[k][j] == INF_T) continue;
                    chmin(es[i][j], es[i][k]+es[k][j]);
                }
            }
        }
    }
};

int main(){
    int N, M;
    cin >> N >> M;

    Union_Find_Tree uf(2*N);
    vector<int> u(M), v(M), t(M);
    bool flag = true;
    rep(i, M){
        cin >> u[i] >> v[i] >> t[i]; u[i]--, v[i]--;
        if(uf.same(u[i], v[i])) flag = false;
        uf.unite(u[i], N+v[i]), uf.unite(N+u[i], v[i]);
    }

    if(!flag) {cout << "NO\n"; return 0;}

    vector<int> c(N);
    rep(i, N){
        if(uf.same(0, i)) c[i] = 0; //
        else c[i] = 1; //
    }

    List<int> G(N);

    rep(i, M){
        if(t[i] == 0){
            if(c[u[i]] == 0){
                G.add_edge(u[i], v[i], 0, true);
                G.add_edge(v[i], u[i], 1, true);
            }
            else{
                G.add_edge(u[i], v[i], 1, true);
                G.add_edge(v[i], u[i], 0, true);
            }
        }
        else{
            if(c[u[i]] == 0){
                G.add_edge(u[i], v[i], 0, true);
                G.add_edge(v[i], u[i], 0, true);
            }
            else{
                G.add_edge(u[i], v[i], 1, true);
                G.add_edge(v[i], u[i], -1, true);
            }
        }
    }

    G.warshall_floyd();

    rep(i, N){
        if(G.es[i][i] < 0) {cout << "NO\n"; return 0;}
    }

    int S = -1, D = -inf;
    rep(i, N){
        rep(j, N){
            int tmp = G.es[i][j]*2-c[i]+c[j];
            if(chmax(D, tmp)) S = i;
        }
    }

    cout << "YES\n" << D << '\n';
    rep(i, N){
        cout << G.es[S][i]*2+c[i] << ' ';
    }
    cout << '\n';
}