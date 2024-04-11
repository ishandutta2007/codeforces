#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    bool dp[N][5];
    int rev[N][5];
    fill(dp[0], dp[1], true);
    fill(dp[1], dp[N], false);

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 5; ++j) {
            // a[i]j
            if (a[i - 1] < a[i]) {
                for (int k = 0; k < j; ++k) {
                    if (dp[i - 1][k]) {
                        dp[i][j] = true;
                        rev[i][j] = k;
                    }
                }
            } else if (a[i - 1] > a[i]) {
                for (int k = j + 1; k < 5; ++k) {
                    if (dp[i - 1][k]) {
                        dp[i][j] = true;
                        rev[i][j] = k;
                    }
                }
            } else {
                for (int k = 0; k < 5; ++k) {
                    if (k == j) continue;
                    if (dp[i - 1][k]) {
                        dp[i][j] = true;
                        rev[i][j] = k;
                    }
                }
            }
        }
    }

    for (int i = 0; i < 5; ++i) {
        if (dp[N - 1][i]) {
            vector<int> ans = {i};

            int f = i, n = N - 1;
            while (n > 0) {
                f = rev[n][f];
                ans.push_back(f);
                --n;
            }

            reverse(ans.begin(), ans.end());
            for (int f : ans) {
                cout << f + 1 << " ";
            }
            cout << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}