#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        string a, b;
        cin >> a >> b;
        vector<int> c(n);
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                c[i] = 1;
            }
        }
        int d = 0;
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            if (d != c[i]) {
                ans.emplace_back(i + 1);
                ans.emplace_back(1);
                ans.emplace_back(i + 1);
            }
        }
        cout << ans.size() << " ";
        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}