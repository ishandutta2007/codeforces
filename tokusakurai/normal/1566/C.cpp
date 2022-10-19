#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
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
// const int MOD = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<string> S(2);
        rep(i, 2) cin >> S[i];

        vector<vector<int>> dp(N + 1, vector<int>(4, -inf));
        dp[0][0] = 0;

        rep(i, N + 1) {
            chmax(dp[i][0], dp[i][1] + 1);
            chmax(dp[i][0], dp[i][2] + 0);
            chmax(dp[i][0], dp[i][3] + 2);

            if (i == N) break;

            rep(j, 4) {
                int nj = j;
                rep(k, 2) {
                    int x = S[k][i] - '0';
                    nj |= (1 << x);
                }
                chmax(dp[i + 1][nj], dp[i][j]);
            }
        }

        cout << dp[N][0] << '\n';
    }
}