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
    int N, M;
    cin >> N >> M;
    string S, T;
    cin >> S >> T;

    vector<vector<int>> dp(N, vector<int>(M, 0));
    rep(i, N){
        if(S[i] == T[0]) dp[i][0] = 2;
        else if(i > 0 && S[i-1] == T[0]) dp[i][0] = 1;
    }
    rep(i, M){
        if(S[0] == T[i]) dp[0][i] = 2;
        else if(i > 0 && S[0] == T[i-1]) dp[0][i] = 1;
    }

    int ans = 0;
    rep2(i, 1, N-1){
        rep2(j, 1, M-1){
            int x = (S[i] == T[j]? 2 : -2);
            chmax(dp[i][j], dp[i-1][j-1]+x);
            chmax(dp[i][j], dp[i-1][j]-1), chmax(dp[i][j], dp[i][j-1]-1);
        }
    }

    rep(i, N){
        rep(j, M) chmax(ans, dp[i][j]);
    }
    cout << ans << '\n';
}