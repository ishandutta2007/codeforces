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

vector<int> ans(1000), par(1000, -1);
vector<vector<int>> a;
int K;

void dfs(vector<int> v, int pre = -1){
    int n = sz(v), m = -inf;

    each(e, v){
        each(u, v) chmax(m, a[e][u]);
    }

    if(n == 1){
        par[v[0]] = pre, ans[v[0]] = m;
        return;
    }

    int now = K++;
    par[now] = pre, ans[now] = m;

    vector<bool> used(n, false);
    rep(i, n){
        if(used[i]) continue;

        vector<int> nxt;

        rep(j, n){
            if(a[v[i]][v[j]] < m){
                used[j] = true, nxt.eb(v[j]);
            }
        }

        dfs(nxt, now);
    }
}

int main(){
    int N; cin >> N;

    a.assign(N, vector<int>(N));
    rep(i, N){
        rep(j, N) cin >> a[i][j];
    }

    K = N;

    vector<int> v(N);
    iota(all(v), 0);
    dfs(v);

    cout << K << '\n';
    rep(i, K) cout << ans[i] << (i == K-1? '\n' : ' ');

    cout << N+1 << '\n';
    rep(i, K){
        if(par[i] != -1) cout << i+1 << ' ' << par[i]+1 << '\n';
    }
}