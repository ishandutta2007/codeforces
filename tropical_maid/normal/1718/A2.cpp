#include <bits/stdc++.h>

using namespace std;

int n;
int A[100001];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        cin >> n;
        map<int, int> dp;
        dp[0] = 0;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            cin >> A[i];
            A[i] ^= A[i - 1];
            auto it = dp.find(A[i]);
            if (it != dp.end()) {
                ans = max(ans, it->second + 1);
            }
            dp[A[i]] = ans;
        }
        printf("%d\n", n - ans);
    }
}