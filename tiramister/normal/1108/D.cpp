#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int INF = 1 << 25;

int main() {
    const string RGB = "RGB";

    int N;
    string S;
    cin >> N >> S;

    int dp[N + 1][3];
    fill(dp[0], dp[1], 0);
    fill(dp[1], dp[N + 1], INF);

    int pre[N + 1][3];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                if (j == k) continue;
                int cost = (S[i] != RGB[k]);

                if (dp[i + 1][k] <= dp[i][j] + cost) continue;
                dp[i + 1][k] = dp[i][j] + cost;
                pre[i + 1][k] = j;
            }
        }
    }

    int b = min_element(dp[N], dp[N + 1]) - dp[N];
    cout << dp[N][b] << endl;

    string ans = "";
    for (int i = N; i > 0; --i) {
        ans.push_back(RGB[b]);
        b = pre[i][b];
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}