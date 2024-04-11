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
            a[i]--;
        }
        int ng = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 != i % 2) {
                ng = 1;
                break;
            }
        }
        if (ng) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans;
        for (int i = n - 1; i > 0; i -= 2) {
            int x = -1;
            for (int j = 0; j < i + 1; j += 2) {
                if (a[j] == i) {
                    x = j;
                    break;
                }
            }
            ans.emplace_back(x + 1);
            reverse(a.begin(), a.begin() + x + 1);
            int y = -1;
            for (int j = 1; j < i + 1; j += 2) {
                if (a[j] == i - 1) {
                    y = j;
                    break;
                }
            }
            ans.emplace_back(y);
            reverse(a.begin(), a.begin() + y);
            ans.emplace_back(y + 2);
            reverse(a.begin(), a.begin() + y + 2);
            ans.emplace_back(3);
            reverse(a.begin(), a.begin() + 3);
            ans.emplace_back(i + 1);
            reverse(a.begin(), a.begin() + i + 1);
        }
        cout << ans.size() << '\n';
        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
        // debug(a);
    }
    return 0;
}