#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, L; cin >> n >> L;
    vector<int> c(n);
    for(int i = 0; i < n; i++)
        cin >> c[i];
    for(int i = 1; i < n; i++)
        c[i] = min(c[i], 2 * c[i - 1]);
    long long ans = (L / (1 << (n - 1))) * 1LL * c[n - 1];
    L %= (1 << (n - 1));
    vector<long long> dp(n);
    for(int i = 0; i < n; i++) {
        if(L & (1 << i)) {
            dp[i] = c[i] + (i > 0) * dp[i - 1];
        }
        else {
            dp[i] = min((long long) c[i], (long long) (i > 0) * dp[i - 1]);
        }
    }
    cout << dp[n - 1] + ans << "\n";
}