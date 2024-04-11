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
        sort(a.begin(), a.end());
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int b = a[j] % a[i];
                if (!binary_search(a.begin(), a.end(), b)) {
                    ans.emplace_back(a[j], a[i]);
                    if ((int) ans.size() == n / 2) {
                        break;
                    }
                }
            }
            if ((int) ans.size() == n / 2) {
                break;
            }
        }
        for (auto [x, y] : ans) {
            cout << x << " " << y << '\n';
        }
    }
    return 0;
}