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

struct Random_Number_Generator{
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator () (int64_t l, int64_t r){
        uniform_int_distribution<int64_t> dist(l, r-1);
        return dist(mt);
    }

    int64_t operator () (int64_t r){ 
        return (*this)(0, r);
    }
};

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
    int N, A, B; cin >> N >> A >> B;

    Union_Find_Tree uf1(N), uf2(N);

    rep(i, A){
        int u, v; cin >> u >> v; u--, v--;
        uf1.unite(u, v);
    }
    rep(i, B){
        int u, v; cin >> u >> v; u--, v--;
        uf2.unite(u, v);
    }

    cout << N-1-max(A, B) << '\n';

    rep(i, N){
        if(!uf1.same(0, i) && !uf2.same(0, i)){
            cout << 1 << ' ' << i+1 << '\n';
            uf1.unite(0, i), uf2.unite(0, i);
        }
    }

    vector<int> id1, id2;

    rep(i, N){
        if(uf1.same(0, i) && !uf2.same(0, i) && uf2[i] == i) id1.eb(i);
        if(uf2.same(0, i) && !uf1.same(0, i) && uf1[i] == i) id2.eb(i);
    }

    rep(i, min(sz(id1), sz(id2))){
        cout << id1[i]+1 << ' ' << id2[i]+1 << '\n';
    }
}