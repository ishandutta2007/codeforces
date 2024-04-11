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
        string t;
        cin >> t;
        t = "0" + t;
        vector<int> ans(n + 1, n + 10);
        ans[0] = 0;
        for (int i = 0; i <= n; i++) {
            if (t[i] == '1') {
                ans[i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                if (t[j] == '1') {
                    break;
                }
                ans[j] = min(ans[j], i);
            }
        }
        cout << accumulate(ans.begin(), ans.end(), 0LL) << '\n';
    }
    return 0;
}