#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<array<int, 2>> a(N);
        for (int b : {0, 1}) {
            for (int i = 0; i < N; ++i) {
                char ch;
                cin >> ch;
                a[i][b] = ch - '0';
            }
        }
        int last[2] = {-1, -1};
        vector<int> dp(N);
        for (int i = 0; i < N; ++i) {
            if (a[i][0] != a[i][1]) {
                dp[i] = 2 + (i ? dp[i - 1] : 0);
            } else {
                int b = a[i][0];
                if (int j = last[b ^ 1]; j != -1) {
                    dp[i] = 2 + (j ? dp[j - 1] : 0);
                }
                dp[i] = max(dp[i], !b + (i ? dp[i - 1] : 0));
            }
            for (int b : {0, 1}) {
                last[a[i][b]] = i;
            }
        }
        cout << dp.back() << '\n';
    }
    exit(0);
}