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
    int m = 10010;
    vector<int> c(m, 1);
    for (int i = 1; i * i < m; i++) {
        c[i * i] = 0;
    }
    while (tt--) {
        int n;
        cin >> n;
        string ans = "NO";
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (c[a]) {
                ans = "YES";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}