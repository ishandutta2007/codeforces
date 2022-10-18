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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 1LL * n * (n + 1) / 2;
    auto f = [&](int i) {
        if (i < 0 || i >= n || a[i] == a[i + 1]) {
            return 0LL;
        }
        return (i + 1) * 1LL * (n - i - 1);
    };
    for (int i = 0; i < n - 1; i++) {
        ans += f(i);
    }
    while (m--) {
        int i, x;
        cin >> i >> x;
        i--;
        ans -= f(i - 1);
        ans -= f(i);
        a[i] = x;
        ans += f(i - 1);
        ans += f(i);
        cout << ans << '\n';
    }
    return 0;
}