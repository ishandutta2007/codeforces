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
        int n, z;
        cin >> n >> z;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            ans = max(ans, a | z);
        }
        cout << ans << '\n';
    }
    return 0;
}