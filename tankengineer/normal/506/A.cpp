#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 30005;

int n, d;

vector<pair<int, int> > dp[N];

int cnt[N];

int main() {
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
        int pos;
        scanf("%d", &pos);
        ++cnt[pos];
    }
    dp[d].push_back(make_pair(d, cnt[d]));
    int ans = 0;
    for (int i = 0; i < 30001; ++i) {
        if (dp[i].size() == 0) {
            continue;
        }
        sort(dp[i].begin(), dp[i].end());
        reverse(dp[i].begin(), dp[i].end());
        for (int j = 0; j < (int)dp[i].size(); ++j) {
            if (j && dp[i][j - 1].first == dp[i][j].first) {
                continue;
            }
            ans = max(ans, dp[i][j].second);
            int l = dp[i][j].first;
            if (l - 1 > 0 && i + l - 1 < 30001) {
                dp[i + l - 1].push_back(make_pair(l - 1, dp[i][j].second + cnt[i + l - 1]));
            }
            if (l > 0 && i + l < 30001) {
                dp[i + l].push_back(make_pair(l, dp[i][j].second + cnt[i + l]));
            }
            if (l + 1 > 0 && i + l + 1 < 30001) {
                dp[i + l + 1].push_back(make_pair(l + 1, dp[i][j].second + cnt[i + l + 1]));
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}