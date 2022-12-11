#include <iostream>

using namespace std;

const int MAX_N = 60;
long long pref[MAX_N];
long long a[MAX_N];
int n, k;

long long find_s(int l, int r) {
    if (l == r + 1) return (1ll << 60) - 1;
    return pref[r] - pref[l - 1];
}

bool check(long long mask) {
    bool dp[k + 1][n + 1];
    long long s = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
        if ((s & mask) == mask) dp[1][i] = 1;
        else dp[1][i] = 0;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = i; j <= n; j++) {
            dp[i][j] = 0;
            s = 0;
            for (int last = j; last >= i; last--) {
                s += a[last];
                if ((s & mask) == mask && dp[i - 1][last - 1]) {
                    dp[i][j] = 1;
                    break;
                }
            }
        }
    }
    return dp[k][n];
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pref[0] = 0;
    for (int i = 1; i <= n; i++) pref[i] = pref[i - 1] + a[i];
    long long ans = 0;
    for (int i = 60; i >= 0; i--) {
        if (check(ans | (1ll << i))) ans |= (1ll << i);
    }
    cout << ans << endl;
    return 0;
}