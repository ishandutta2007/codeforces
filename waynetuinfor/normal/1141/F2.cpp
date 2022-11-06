#include <bits/stdc++.h>
using namespace std;

const int maxn = 1500 + 5;
int a[maxn], s[maxn];
int dp[maxn][maxn];
pair<int, int> f[maxn][maxn];
map<int, vector<pair<int, int>>> p;
map<int, int> px;
map<int, pair<int, int>> where;

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i][j] = 1;
            p[s[i] - s[j - 1]].emplace_back(i, j);
        }
    }
    for (auto &v : p) {
        sort(v.second.begin(), v.second.end());
        reverse(v.second.begin(), v.second.end());
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            int sum = s[i] - s[j - 1];
            while (p[sum].size() > 0 && p[sum].back().first < j) {
                int x = p[sum].back().first, y = p[sum].back().second;
                if (dp[x][y] > px[sum]) {
                    px[sum] = dp[x][y];
                    where[sum] = make_pair(x, y);
                }
                p[sum].pop_back();
            }
            if (px[sum] + 1 > dp[i][j]) {
                dp[i][j] = px[sum] + 1;
                f[i][j] = where[sum];
            }
        }
    }
    int ans = 0, x = -1, y = -1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dp[i][j] > ans) {
                ans = dp[i][j];
                x = i;
                y = j;
            }
        }
    }
    printf("%d\n", ans);
    while (x && y) {
        printf("%d %d\n", y, x);
        tie(x, y) = f[x][y]; 
    }
}