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
};
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
};

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main() {
    int N, K;
    string S;
    cin >> N >> K >> S;

    vector<vector<int>> c(K, vector<int>(N + 1, 0));
    rep(i, K) {
        rep3(j, N - 1, 0) {
            if (S[j] == '?' || S[j] == char('a' + i))
                c[i][j] = c[i][j + 1] + 1;
            else
                c[i][j] = 0;
        }
    }

    vector<vector<int>> nxt(K, vector<int>(N + 1, inf));

    int L = 0, R = N + 1; // [L,R)

    while (R - L > 1) {
        int M = (L + R) / 2;

        rep(i, K) {
            rep3(j, N - 1, 0) {
                if (c[i][j] >= M)
                    nxt[i][j] = j;
                else
                    nxt[i][j] = nxt[i][j + 1];
            }
        }

        vector<int> dp(1 << K, inf);
        dp[0] = 0;

        rep(i, 1 << K) {
            if (dp[i] == inf) continue;
            rep(j, K) {
                if ((i >> j) & 1) continue;
                chmin(dp[i | (1 << j)], nxt[j][dp[i]] + M);
            }
        }

        (dp.back() <= N ? L : R) = M;
    }

    cout << L << '\n';
}