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
        string s;
        cin >> s;
        int l = k;
        k = min(k, 22);
        while ((1 << (k - 1)) > n) {
            k--;
        }
        vector<int> ng(1 << k);
        vector<int> one(n);
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '1') {
                one[i + 1] = one[i] + 1;
            }
        }
        for (int i = l - k; i < n - k + 1; i++) {
            if (one[i] < l - k) {
                continue;
            }
            int t = 0;
            for (int j = 0; j < k; j++) {
                if (s[i + j] == '0') {
                    t += 1 << (k - 1 - j);
                }
            }
            ng[t] = 1;
        }
        if (accumulate(ng.begin(), ng.end(), 0) == (1 << k)) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        string ans(l, '0');
        for (int i = 0; i < (1 << k); i++) {
            if (!ng[i]) {
                for (int j = 0; j < k; j++) {
                    if (i & (1 << j)) {
                        ans[l - 1 - j] = '1';
                    }
                }
                break;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}