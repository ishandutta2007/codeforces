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
const ll INF = (1LL<<31)-1;
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
    
    void clear() {fill(begin(data), end(data), -1);}
};

int main(){
    int N; cin >> N;

    map<int, vector<pii>> mpx, mpy;
    set<pii> ex;

    vector<int> x(N), y(N);
    vector<int> xs, ys;

    rep(i, N){
        cin >> x[i] >> y[i];
        mpx[x[i]].eb(y[i], i), mpy[y[i]].eb(x[i], i);
        xs.eb(x[i]), ys.eb(y[i]);
        ex.emplace(x[i], y[i]);
    }

    sort(all(xs)), sort(all(ys));
    xs.erase(unique(all(xs)), end(xs));
    ys.erase(unique(all(ys)), end(ys));

    vector<int> u, v, w;

    each(e, mpx){
        sort(all(e.second));
        auto a = e.second;
        rep(i, sz(a)-1){
            u.eb(a[i].second), v.eb(a[i+1].second), w.eb(a[i+1].first-a[i].first);
        }
    }

    each(e, mpy){
        sort(all(e.second));
        auto a = e.second;
        rep(i, sz(a)-1){
            u.eb(a[i].second), v.eb(a[i+1].second), w.eb(a[i+1].first-a[i].first);
        }
    }

    int a = sz(xs), b = sz(ys);
    vector<vector<int>> L(a, vector<int>(b, -1)), R(a, vector<int>(b, -1)), D(a, vector<int>(b, -1)), U(a, vector<int>(b, -1));
    vector<vector<bool>> ng(a, vector<bool>(b, false));

    rep(i, a) rep(j, b){
        int X = xs[i], Y = ys[j];
        if(ex.count(pii(X, Y))) ng[i][j] = true;
        
        vector<pii> A = mpx[X];
        auto it = lower_bound(all(A), pii(Y, 0));
        if(it != end(A)) U[i][j] = (*it).second;
        if(it != begin(A)) D[i][j] = (*(--it)).second;

        vector<pii> B = mpy[Y];
        it = lower_bound(all(B), pii(X, 0));
        if(it != end(B)) R[i][j] = (*it).second;
        if(it != begin(B)) L[i][j] = (*(--it)).second;
    }

    int M = sz(u);
    
    ll l = 0, r = INF; //(l,r]
    while(r-l > 1){
        ll m = (l+r)/2;
        Union_Find_Tree uf(N);

        int n = N;
        rep(i, M){
            if(w[i] <= m) n -= uf.unite(u[i], v[i]);
        }

        if(n == 1) {r = m; continue;}

        vector<int> root(N);
        rep(i, N) root[i] = uf[i];

        if(n == 2){
            bool flag = false;
            rep(i, M){
                if(w[i] <= 2*m){
                    if(root[u[i]] != root[v[i]]) {flag = true; break;}
                }
            }
            if(flag) {r = m; continue;}
        }

        if(n <= 4){
            bool flag = false;
            rep(i, a){
                rep(j, b){
                    if(ng[i][j]) continue;

                    vector<int> vs(4);
                    int ri = R[i][j], li = L[i][j], ui = U[i][j], di = D[i][j];

                    if(ri != -1 && x[ri] <= xs[i]+m) vs[0] = root[ri];
                    else vs[0] = -1;

                    if(li != -1 && x[li] >= xs[i]-m) vs[1] = root[li];
                    else vs[1] = -1;

                    if(ui != -1 && y[ui] <= ys[j]+m) vs[2] = root[ui];
                    else vs[2] = -1;

                    if(di != -1 && y[di] >= ys[j]-m) vs[3] = root[di];
                    else vs[3] = -1;

                    sort(all(vs));
                    int tmp = (vs[0] != -1);
                    rep(k, sz(vs)-1) tmp += (vs[k] != vs[k+1]);

                    if(tmp == n) {flag = true; break;}
                }
                if(flag) break;
            }

            if(flag) {r = m; continue;}
        }

        l = m;
    }

    cout << (r == INF? -1 : r) << '\n';
}