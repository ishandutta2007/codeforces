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
        vector<int> ans;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[i] == a[j]) {
                j++;
            }
            if (i + 1 == j) {
                ans.clear();
                ans.emplace_back(-2);
                break;
            }
            ans.emplace_back(j - 1);
            for (int k = i; k < j - 1; k++) {
                ans.emplace_back(k);
            }
        }
        for (int i = 0; i < (int) ans.size(); i++) {
            cout << ans[i] + 1 << " \n"[i == (int) ans.size() - 1];
        }
    }
    return 0;
}