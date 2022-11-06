#include <bits/stdc++.h>
using namespace std;

const int maxn = 18;
int a[maxn], n, m, k, c[maxn][maxn];
long long dp[maxn][1 << maxn];
bool v[maxn][1 << maxn];

long long go(int p, int s) {
    if (__builtin_popcount(s) == n - m) return 0;
    if (v[p][s]) return dp[p][s];
    for (int i = 0; i < n; ++i) if ((1 << i) & s) {
        dp[p][s] = max(dp[p][s], go(i, s ^ (1 << i)) + a[i] + c[p][i]);
    }
    v[p][s] = true;
    return dp[p][s];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ind = 1;
    while (k--) {
        int x, y; cin >> x >> y; --x; --y;
        cin >> c[x][y];
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, go(i, ((1 << n) - 1) ^ (1 << i)) + a[i]);
    }
    cout << ans << endl;
    return 0;
}