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

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> n(3);
    rep(i, 3) cin >> n[i];

    Union_Find_Tree uf(2*N);
    bool flag = true;
    rep(i, M){
        int u, v; cin >> u >> v; u--, v--;
        if(uf.same(u, v)) flag = false;
        uf.unite(N+u, v), uf.unite(u, N+v);
    }

    if(!flag) {cout << "NO\n"; return 0;}

    vector<vector<int>> a(2*N), b(2*N);
    rep(i, 2*N){
        if(i < N) a[uf[i]].eb(i);
        else b[uf[i]].eb(i-N);
    }

    vector<bool> used(N, false);
    vector<pii> tmp;
    vector<vector<int>> x, y;
    
    rep(i, 2*N){
        int p = sz(a[i]), q = sz(b[i]);
        if(p+q == 0) continue;
        if(used[i%N]) continue;
        each(e, a[i]) used[e] = true;
        each(e, b[i]) used[e] = true;
        tmp.eb(p, q);
        x.eb(a[i]), y.eb(b[i]);
    }
    
    int K = sz(tmp);
    vector<vector<int>> dp(K+1, vector<int>(N+1, -1));
    dp[0][0] = 0;

    rep(i, K){
        rep(j, N+1){
            if(dp[i][j] == -1) continue;
            int nj = j+tmp[i].first;
            if(nj <= N) dp[i+1][nj] = 0;
            nj = j+tmp[i].second;
            if(nj <= N) dp[i+1][nj] = 1;
        }
    }

    if(dp[K][n[1]] == -1) {cout << "NO\n"; return 0;}
    
    vector<int> ans(N);
    int cnt = 0;
    int ptr = n[1];
    rep3(i, K, 1){
        if(dp[i][ptr] == 0){
            each(e, x[i-1]) ans[e] = 2;
            each(e, y[i-1]){
                if(cnt < n[0]) ans[e] = 1, cnt++;
                else ans[e] = 3;
            }
            ptr -= tmp[i-1].first;
        }
        else{
            each(e, y[i-1]) ans[e] = 2;
            each(e, x[i-1]){
                if(cnt < n[0]) ans[e] = 1, cnt++;
                else ans[e] = 3;
            }
            ptr -= tmp[i-1].second;
        }
    }

    cout << "YES\n";
    each(e, ans) cout << e; cout << '\n';
}