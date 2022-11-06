#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, maxp = 17;
const int inf = 1e9;
int a[maxn];
int dp[maxn][1 << maxp], mask[61], t[maxn][1 << maxp], tk[maxn][1 << maxp];
int p[maxp] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    reverse(a + 1, a + n + 1);
    for (int i = 1; i < (1 << maxp); ++i) dp[0][i] = inf;
    dp[0][0] = 0;
    int cur = 1;
    for (int i = 1; i <= 60; ++i) {
        for (int j = 0; j < maxp; ++j) if (i % p[j] == 0) mask[i] ^= (1 << j);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < (1 << maxp); ++j) dp[i][j] = inf;
        for (int j = 1; j <= 60; ++j) {
            for (int k = 0; k < (1 << maxp); ++k) if ((k & mask[j]) == 0) {
                if (dp[i - 1][k] + abs(a[i] - j) < dp[i][k ^ mask[j]]) {
                    dp[i][k ^ mask[j]] = dp[i - 1][k] + abs(a[i] - j);
                    t[i][k ^ mask[j]] = k;
                    tk[i][k ^ mask[j]] = j;
                }
            }
        }
    }
    int bst = -1, ans = inf;
    for (int i = 0; i < (1 << maxp); ++i) {
        if (dp[n][i] < ans) ans = dp[n][i], bst = i;
    }
    for (int i = n; i >= 1; --i) {
        cout << tk[i][bst] << ' ';
        bst = t[i][bst];
    }
    cout << endl;
    return 0;
}