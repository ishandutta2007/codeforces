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
    int N;
    ll K;
    cin >> N >> K;
    ll l[N], r[N], a[N];
    rep(i, N) cin >> l[i] >> r[i] >> a[i];
    ll dp[N+1][N+1];
    fill(dp[0], dp[N+1], INF);
    dp[0][0] = 0;
    ll rem[N];
    fill(rem, rem+N, K);
    rep(i, N){
        rep(j, i+1){
            if(dp[i][j] == INF) continue;
            ll x = rem[j]+K*(r[i]-l[i]);
            if(x < a[i]) rem[j] = -INF;
            else{
                chmin(dp[i+1][j], dp[i][j]+a[i]);
                rem[j] = (x-a[i])%K;
                if(x-a[i] >= K || i == N-1 || r[i] < l[i+1]){
                    chmin(dp[i+1][i+1], dp[i][j]+a[i]+rem[j]);
                }
            }
        }
    }
    ll ans = INF;
    rep(i, N+1) chmin(ans, dp[N][i]);
    cout << (ans == INF? -1 : ans) << endl;
}