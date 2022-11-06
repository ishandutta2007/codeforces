#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n + n);
    for (int i = 0; i < n + n; ++i) scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    int sum = accumulate(a.begin() + 2, a.end(), 0);
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    dp[0][0] = 0;
    for (int i = 2; i < n + n; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            for (int k = sum; k >= 0; --k) {
                if (dp[j][k] != -1) continue;
                if (j - 1 >= 0 && k - a[i] >= 0 && dp[j - 1][k - a[i]] != -1) dp[j][k] = i;
            }
        }
    }
    int ans = sum + 1, w = -1;
    for (int i = 0; i <= sum; ++i) {
        if (dp[n - 1][i] == -1) continue;
        if (max(i, sum - i) < ans) {
            ans = max(i, sum - i);
            w = i;
        }
    }
    vector<bool> choose(n + n);
    choose[0] = true;
    for (int j = n - 1, k = w; j > 0; ) {
        assert(dp[j][k] != -1);
        choose[dp[j][k]] = true;
        k -= a[dp[j][k]];
        j--;
    }
    vector<int> x, y;
    for (int i = 0; i < n + n; ++i) {
        if (choose[i]) x.push_back(a[i]);
        else y.push_back(a[i]);
    }
    reverse(y.begin(), y.end());
    for (int u : x) printf("%d ", u); puts("");
    for (int u : y) printf("%d ", u); puts("");
}