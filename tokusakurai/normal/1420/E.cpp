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
    cin >> N;
    int a[N];
    int n = 0;
    rep(i, N){
        cin >> a[i];
        if(a[i] == 0) n++;
    }
    vector<int> v;
    for(int i = 0; i <= N;){
        int j = 0;
        while(i+j < N && a[i+j] == 0) j++;
        v.pb(j);
        i += j+1;
    }
    vector<int> cnt;
    int s = 0;
    for(auto &e: v) cnt.pb(s += e);
    int K = sz(v);
    ll dp[K+1][n+1][N*(N-1)/2+1];
    rep(i, K+1) rep(j, n+1) rep(k, N*(N-1)/2+1) dp[i][j][k] = INF;
    dp[0][0][0] = 0;
    rep(i, K){
        rep2(j, 0, n){
            rep2(k, 0, N*(N-1)/2){
                if(dp[i][j][k] == INF) continue;
                rep2(l, 0, n-j){
                    int ni = i+1, nj = j+l, nk = k+abs(nj-cnt[i]);
                    if(nk <= N*(N-1)/2) chmin(dp[ni][nj][nk], dp[i][j][k]+l*(l-1)/2);
                }
            }
        }
    }
    ll ans = INF, base = n*(n-1)/2;
    rep2(i, 0, N*(N-1)/2){
        chmin(ans, dp[K][n][i]);
        cout << base-ans << ' ';
    }
    cout << endl;
}