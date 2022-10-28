#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> events(2 * n + 1);
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        events[i * 2 - 1] = {l, i};
        events[i * 2] = {r + 1, -i};
    }

    sort(events.begin(), events.end());
    vector<vector<int>> dp(2 * n + 1, vector<int>(1 << k));
    vector<int> segs(k);
    int fill = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int j = 0;
        if (events[i].second > 0) {
            while (fill & (1 << j)) {
                j++;
            }
            segs[j] = events[i].second;
            fill ^= 1 << j;
        } else {
            while (segs[j] != -events[i].second) {
                j++;
            }
            fill ^= 1 << j;
        }
        for (int l = 0; l < (1 << k); l++) {
            if ((l | fill) != fill) continue;
            if (fill & (1 << j)) {
                dp[i][l] = dp[i - 1][l & ~(1 << j)];
            } else {
                dp[i][l] = max(dp[i - 1][l & ~(1 << j)], dp[i - 1][l | (1 << j)]);
            }
            if (__builtin_parity(l) && i + 1 < events.size()) {
                dp[i][l] += events[i + 1].first - events[i].first;
            }
        }
    }
    cout << dp.back()[0] << '\n';
}