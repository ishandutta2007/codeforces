#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
pair<int, int> p[maxn];
int dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> p[i].first >> p[i].second;
    sort(p + 1, p + n + 1);
    for (int i = 1; i <= n; ++i) {
        int to = p[i].first - p[i].second;
        int ind = prev(lower_bound(p + 1, p + n + 1, make_pair(to, -1))) - p;
        dp[i] = dp[ind] + i - ind - 1;
    }
    int ans = dp[n];
    for (int i = n; i >= 1; --i) ans = min(ans, dp[i - 1] + n - i + 1);
    cout << ans << endl;
}