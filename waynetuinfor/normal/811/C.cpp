#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
int a[maxn], x[maxn][maxn], l[maxn], r[maxn], dp[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < maxn; ++i) {
        l[i] = n + 1, r[i] = 0;
        for (int j = 1; j <= n; ++j) if (a[j] == i) {
            l[i] = min(l[i], j), r[i] = max(r[i], j);
        }
    }
    for (int i = 1; i <= n; ++i) {
        memset(v, false, sizeof(v));
        for (int j = i; j <= n; ++j) {
            x[i][j] = x[i][j - 1];
            if (v[a[j]]) continue;
            x[i][j] ^= a[j];
            v[a[j]] = true;
        }
    } 
    for (int i = 1; i <= n; ++i)  {
        int osas = l[a[i]];
        dp[i] = dp[i - 1];
        if (r[a[i]] == i) for (int j = i; j > 0; --j) {
            if (r[a[j]] > i) break;
            if (l[a[j]] < j) osas = min(osas, l[a[j]]);
            if (j > osas) continue;
            dp[i] = max(dp[i], dp[j - 1] + x[j][i]);
        }
    } 
    cout << dp[n] << endl;
    return 0;
}