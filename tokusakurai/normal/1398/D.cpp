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
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    int R, G, B;
    cin >> R >> G >> B;
    int r[R], g[G], b[B];
    rep(i, R) cin >> r[i];
    rep(i, G) cin >> g[i];
    rep(i, B) cin >> b[i];
    sort(r, r+R, greater<int>());
    sort(g, g+G, greater<int>());
    sort(b, b+B, greater<int>());

    int dp[R+1][G+1][B+1];
    rep(i, R+1) rep(j, G+1) rep(k, B+1) dp[i][j][k] = 0;
    rep(i, R+1) rep(j, G+1) rep(k, B+1){
        if((i+j+k)&1) continue;
        if(j >= 1 && k >= 1) chmax(dp[i][j][k], dp[i][j-1][k-1]+g[j-1]*b[k-1]);
        if(k >= 1 && i >= 1) chmax(dp[i][j][k], dp[i-1][j][k-1]+b[k-1]*r[i-1]);
        if(i >= 1 && j >= 1) chmax(dp[i][j][k], dp[i-1][j-1][k]+r[i-1]*g[j-1]);
    }
    int ans = 0;
    rep(i, R+1) rep(j, G+1) rep(k, B+1) chmax(ans, dp[i][j][k]);
    cout << ans << endl;
}