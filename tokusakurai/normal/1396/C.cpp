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
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    ll r[3], D;
    rep(i, 3) cin >> r[i];
    cin >> D;
    ll a[N];
    rep(i, N) cin >> a[i];
    ll x[N], y[N];
    rep(i, N){
        x[i] = min(r[0]*(a[i]+1), r[1])+r[0];
        y[i] = r[0]*a[i]+r[2];
    }

    ll dp[N+1];
    fill(dp, dp+N+1, INF);
    dp[0] = D*(N-1);
    rep(i, N){
        chmin(dp[i+1], dp[i]+y[i]);
        chmin(dp[i+1], dp[i]+x[i]+D*2);
        if(i < N-1) chmin(dp[i+2], dp[i]+x[i]+x[i+1]+D*2);
    }

    ll ans = dp[N], sum = 0;
    rep3(i, N-1, 0){
        if(i == N-1) sum += min(y[i], x[i]+D*2);
        else sum += x[i]+D;
        chmin(ans, dp[i]+sum);
    }
    cout << ans << endl;
}