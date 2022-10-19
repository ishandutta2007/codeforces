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
        int N;
        cin >> N;
        vector<int> p(2*N);
        rep(i, 2*N) cin >> p[i];

        vector<vector<int>> dp(2*N+1, vector<int>(2*N+1, inf));
        dp[0][0] = 0;
        
        rep(i, 2*N){
            rep(j, 2*N+1){
                if(dp[i][j] == inf) continue;
                if(dp[i][j] < p[i]) chmin(dp[i+1][i-j+1], p[i]);
                chmin(dp[i+1][j+1], max(dp[i][j], p[i]));
            }
        }

        cout << (dp[2*N][N] == inf? "NO" : "YES") << '\n';
    }
}