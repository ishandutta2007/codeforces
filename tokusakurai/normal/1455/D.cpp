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

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, x;
        cin >> N >> x;
        vector<int> a(N);
        rep(i, N) cin >> a[i];
        vector<int> m(N+1, inf);
        rep3(i, N-1, 0) m[i] = min(m[i+1], a[i]);

        vector<vector<int>> dp(N+1, vector<int>(N+1, inf));
        dp[0][0] = x;
        rep(i, N){
            rep(j, N){
                if(dp[i][j] == inf) continue;
                if(m[i] == a[i]){
                    if(dp[i][j] >= a[i]) chmin(dp[i+1][j], dp[i][j]);
                    else chmin(dp[i+1][j], 1000);
                }
                if(a[i] > dp[i][j] && dp[i][j] <= m[i+1]){
                    chmin(dp[i+1][j+1], a[i]);
                }
            }
        }

        int ans = inf;
        rep(i, N+1) if(dp[N][i] < inf) chmin(ans, i);
        cout << (ans == inf? -1 : ans) << '\n';
    }
}