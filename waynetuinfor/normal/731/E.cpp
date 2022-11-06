#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
long long s[maxn], dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        s[i] = s[i - 1] + a;
    }
    dp[n - 1] = s[n];
    for (int i = n - 2; i >= 1; --i) {
        dp[i] = max(s[i + 1] - dp[i + 1], dp[i + 1]);
    }
    cout << dp[1] << endl;
    return 0;
}