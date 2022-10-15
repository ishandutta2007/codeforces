#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<long long> a(N);
        for (int i = 0; i < N; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<long long> l(M), r(M);
        vector<vector<int>> J(N + 1);
        for (int j = 0; j < M; ++j) {
            cin >> l[j] >> r[j];
            int i = int(lower_bound(a.begin(), a.end(), r[j]) - a.begin());
            if ((i == 0 || a[i - 1] < l[j]) && (i == N || r[j] < a[i])) {
                J[i].push_back(j);
            }
        }
        vector<array<long long, 2>> dp(N, {inf, inf});
        dp[0] = {0, 0};
        for (auto j : J[0]) {
            for (int b : {0, 1}) {
                dp[0][b] = max(dp[0][b], (1 + b) * (a[0] - r[j]));
            }
        }
        for (int i = 1; i < N; ++i) {
            int k = (int)J[i].size();
            if (k == 0) {
                dp[i][0] = dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
            } else {
                sort(J[i].begin(), J[i].end(), [&](int j1, int j2) { return pair(l[j1], r[j1]) < pair(l[j2], r[j2]); });
                long long suffmin = a[i];
                for (int z = k - 1; z >= 0; --z) {
                    int j = J[i][z];
                    for (int b : {0, 1}) {
                        for (int c : {0, 1}) {
                            dp[i][b] = min(dp[i][b], dp[i - 1][c ^ 1] + (1 + c) * (l[j] - a[i - 1]) + (1 + b) * (a[i] - suffmin));
                        }
                    }
                    suffmin = min(suffmin, r[j]);
                }
                for (int b : {0, 1}) {
                    dp[i][b] = min(dp[i][b], dp[i - 1][0] + (1 + b) * (a[i] - suffmin));
                }
            }
        }
        long long add = 0;
        for (auto j : J[N]) {
            add = max(add, l[j] - a[N - 1]);
        }
        long long ans = min(dp[N - 1][0] + 2 * add, dp[N - 1][1] + add);
        cout << ans << '\n';
    }
    exit(0);
}