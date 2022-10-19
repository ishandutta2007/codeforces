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

int mex(vector<int> v){
    int n = sz(v);
    vector<bool> used(n, false);
    each(e, v) used[e] = true;
    rep(i, n){
        if(!used[i]) return i;
    }
    return n;
}

int main(){
    int N, M;
    cin >> N >> M;
    vector<bool> ok(N, true);
    vector<int> u(M), v(M);
    rep(i, M){
        cin >> u[i] >> v[i]; u[i]--, v[i]--;
    }
    vector<int> t(N);
    rep(i, N){
        cin >> t[i]; --t[i];
    }

    vector<int> ids[N];
    rep(i, N) ids[t[i]].eb(i);

    vector<int> es[N];
    rep(i, M){
        if(t[u[i]] == t[v[i]]) {cout << -1 << '\n'; return 0;}
        if(t[u[i]] < t[v[i]]) swap(u[i], v[i]);
        es[u[i]].eb(t[v[i]]);
    }

    rep(i, N){
        if(mex(es[i]) != t[i]) {cout << -1 << '\n'; return 0;}
    }

    rep(i, N){
        each(e, ids[i]) cout << e+1 << ' ';
    }
    cout << '\n';
}