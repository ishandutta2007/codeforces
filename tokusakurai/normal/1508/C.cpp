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
    int N, M; cin >> N >> M;

    vector<set<int>> es(N);
    vector<tuple<int, int, int>> Es;
    int x = 0;

    rep(i, M){
        int u, v, w; cin >> u >> v >> w; u--, v--;
        es[u].emplace(v), es[v].emplace(u);
        Es.eb(w, u, v);
        x ^= w;
    }

    Union_Find_Tree uf(N);
    set<int> s;
    rep(i, N) s.emplace(i);

    rep(i, N){
        if(s.count(i)){
            s.erase(i);
            queue<int> que;
            que.emplace(i);

            while(!empty(que)){
                int p = que.front(); que.pop();

                for(auto it = begin(s); it != end(s);){
                    if(es[p].count(*it)) it++;
                    else{
                        uf.unite(i, *it);
                        que.emplace(*it);
                        it = s.erase(it);
                    }
                }
            }
        }
    }

    int K = 0;
    rep(i, N){
        if(i == uf[i]) K++;
    }

    sort(all(Es));
    ll ans = 0;
    Union_Find_Tree uf2(N);

    each(e, Es){
        auto [w, u, v] = e;
        if(uf.unite(u, v)){
            ans += w;
            uf2.unite(u, v);
        }
        else if(uf2.unite(u, v)){
            chmin(x, w);
        }
    }

    if(1LL*N*(N-1)/2-M == N-K) ans += x;

    cout << ans << '\n';
}