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
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        string ans(n, ' ');
        for (int i = 0; i < n; i++) {
            ans[i] = (char)('a' + (i / k) % 3);
        }
        cout << ans << '\n';
    }
    return 0;
}