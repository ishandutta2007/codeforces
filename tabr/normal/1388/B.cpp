#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string ans = string(n, '9');
        int m = (n - 1) / 4 + 1;
        for (int i = 0; i < m; i++) {
            ans[n - 1 - i] = '8';
        }
        cout << ans << '\n';
    }
    return 0;
}