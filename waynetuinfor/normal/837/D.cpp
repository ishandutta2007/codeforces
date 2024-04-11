#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10, inf = 1e9 + 1;
int dp[maxn][5010];

int main() {
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        long long a; cin >> a;
        int cnt1 = 0, cnt2 = 0;
        while (a % 2 == 0) a /= 2, ++cnt1;
        while (a % 5 == 0) a /= 5, ++cnt2;
        vec.push_back(make_pair(cnt1, cnt2));
    }
    for (int i = 0; i < maxn; ++i) fill(dp[i], dp[i] + 5010, -inf);
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = m; j >= 1; --j) {
            for (int k = 5009; k >= 0; --k) 
                if (k - vec[i].second >= 0) dp[j][k] = max(dp[j][k], dp[j - 1][k - vec[i].second] + vec[i].first);
        }
    }
    int ans = 0;
    for (int i = 0; i < 5010; ++i) ans = max(ans, min(dp[m][i], i));
    cout << ans << endl;
    return 0;
}