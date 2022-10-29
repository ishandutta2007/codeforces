#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
// typedef __int128 LLL;
const LL P = 998244353;
const LL INF = 2e18;
const int N = 5005;
mt19937 rng(time(0));

int T, n;
int a[N], num[N][N], dp[N], cnt[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        rep(l, 1, n) {
            rep(i, 1, n) cnt[i] = 0;
            rep(r, l, n)
                cnt[a[r]]++,
                num[l][r] = max(num[l][r - 1], cnt[a[r]]);
        }
        rep(i, 1, n + 1) {
            dp[i] = -n - 2;
            rep(j, 0, i - 1) if (i == n + 1 || j == 0 || a[j] == a[i]) {
                int d = i - j - 1;
                if (d % 2 == 0 && num[j + 1][i - 1] * 2 <= d)
                    dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        cout << dp[n + 1] - 1 << "\n";
    }
    return 0;
}