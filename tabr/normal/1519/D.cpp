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
    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    long long s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i] * b[i];
    }
    long long ans = s;
    for (int i = 0; i < n; i++) {
        long long t = s;
        for (int j = 1; i + j < n && i - j >= 0; j++) {
            t += (a[i - j] - a[i + j]) * (b[i + j] - b[i - j]);
            ans = max(ans, t);
        }
        t = s;
        for (int j = 0; i + j + 1 < n && i - j >= 0; j++) {
            t += (a[i - j] - a[i + j + 1]) * (b[i + j + 1] - b[i - j]);
            ans = max(ans, t);
        }
    }
    cout << ans << '\n';
    return 0;
}