#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10;
const long long inf = 1e18 + 1;
pair<int, int> p[maxn];
long long dp[maxn], s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; ++i) s[i] = s[i - 1] + p[i].first;
    dp[n + 1] = 0; s[n + 1] = s[n];
    for (int i = n; i >= 1; --i) {
        dp[i] = inf;
        for (int j = i + 1; j <= n + 1; ++j) {
            dp[i] = min(dp[i], dp[j] + s[j - 1] - s[i - 1] - (j - i) * 1ll * p[i].first + p[i].second);
        }
    }
    cout << dp[1] << endl;
    return 0;
}