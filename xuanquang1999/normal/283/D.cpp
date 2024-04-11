#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5005;

int n, dp[MAXN], p2[MAXN];
long long a[MAXN];

bool check(int l, int r) {
    if (a[l] % a[r] != 0)
        return false;
    return (r-l-1 >= p2[r] || p2[r] - p2[l] == r-l);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];

    for(int i = 1; i <= n; ++i) {
        while (a[i]%2 == 0) {
            ++p2[i];
            a[i] /= 2;
        }
    }

    int ans = n;

    for(int i = 1; i <= n; ++i) {
        dp[i] = i-1;
        for(int j = i-1; j >= 1; --j) {
            if (check(j, i))
                dp[i] = min(dp[i], dp[j] + i-j-1);
        }

        ans = min(ans, dp[i] + n-i);
    }

    cout << ans;

    return 0;
}