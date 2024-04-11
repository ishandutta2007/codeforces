#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
double dp[maxn], p[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    for (int i = 1; i <= n; ++i) dp[i] = (dp[i - 1] + p[i - 1]) * p[i];
    double ans = 0.0;
    for (int i = 1; i <= n; ++i) ans += 2.0 * dp[i] + p[i];
    cout << fixed << setprecision(20) << ans << endl;
    return 0;
}