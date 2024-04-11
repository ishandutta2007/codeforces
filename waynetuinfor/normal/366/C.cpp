#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10, inf = 1e9 + 1;
int dp[maxn][maxn * maxn * 20], a[maxn], b[maxn];

int f(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i], b[i] *= k;
    int ans = f(n, 0);
    if (ans <= 0) ans = -1;
    cout << ans << endl;
    return 0;
}

int f(int n, int diff) {
    if (n == 0) {
        if (diff == 0) return 0;
        return -inf;
    }
    if (dp[n][diff + maxn * maxn]) return dp[n][diff + maxn * maxn];
    return dp[n][diff + maxn * maxn] = max(f(n - 1, diff), f(n - 1, diff + b[n] - a[n]) + a[n]);
}