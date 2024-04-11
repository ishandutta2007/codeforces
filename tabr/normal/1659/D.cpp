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
        int k = (int) (accumulate(a.begin(), a.end(), 0LL) / n);
        vector<int> ans(n);
        function<void(int, int)> Solve = [&](int m, int l) {
            if (m == 1) {
                ans[0] = a[0];
                return;
            }
            int nm = (m + 1) / 2;
            int nl = l;
            for (int i = nm; i < m; i++) {
                ans[i] = (a[i] > i);
                nl -= ans[i];
            }
            vector<int> b(nm + 1);
            int c = nm - nl;
            for (int i = nm; i < m; i++) {
                if (ans[i] == 0) {
                    c++;
                }
                if (c < nm) {
                    b[c] -= 1;
                }
            }
            for (int i = 0; i < nm; i++) {
                b[i + 1] += b[i];
                a[i] += b[i];
            }
            Solve(nm, nl);
        };
        Solve(n, k);
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}