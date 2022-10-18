#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    long long ans = 0;
    for (int i = 0; i < n; i += 2) {
        long long l = 0, r = 0;
        long long z = 1, y = 1;
        long long cur = 0;
        for (int j = i + 1; j < n; j += 2) {
            if (j != i + 1) {
                l += c[j - 1];
                cur += c[j - 1];
            }
            y = max(1LL, cur);
            if (l == r) {
                ans += max(0LL, min(c[i], c[j]) - max(z, y) + 1);
            } else if (l > r) {
                ans += max(0LL, min(c[i], c[j] - (l - r)) - max(z, y - (l - r)) + 1);
            } else {
                ans += max(0LL, min(c[j], c[i] - (r - l)) - max(z - (r - l), y) + 1);
            }
            debug(i, j, ans);
            r += c[j];
            cur = max(0LL, cur - c[j]);
            z = max(r - l, z);
            if (r > l + c[i]) {
                break;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}