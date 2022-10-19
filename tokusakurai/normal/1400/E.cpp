#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1000000007;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

ll a[5000];

ll dfs(int l, int r, ll h){
    if(l == r) return 0;
    ll ret = 0, m = inf;
    rep2(i, l, r-1) chmin(m, a[i]);
    ll cnt = 0;
    vector<int> ids;
    ids.pb(l-1);
    rep2(i, l, r-1) if(a[i] == m) cnt++, ids.pb(i);
    ids.pb(r);
    ll tmp = m-h-cnt;
    rep2(i, 0, cnt){
        tmp += dfs(ids[i]+1, ids[i+1], m);
    }
    chmin(ret, tmp);
    return ret;
}

int main(){
    int N;
    cin >> N;
    rep(i, N) cin >> a[i];
    cout << N+dfs(0, N, 0) << endl;
}