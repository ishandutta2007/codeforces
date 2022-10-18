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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> pos(n + 1);
        for (int i = 0; i < n; i++) {
            pos[a[i]] = i;
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[a[i] - 1] = (i == n - 1 ? 1 : i + 2);
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}