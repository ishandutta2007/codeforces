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
        vector<int> ans;
        int j = 0;
        for (int i = n - 1; i >= 0; i--) {
            if ((a[j] == b[i]) == ((n - 1 - i) % 2 == 0)) {
                ans.emplace_back(1);
            }
            ans.emplace_back(i + 1);
            if ((n - 1 - i) % 2 == 0) {
                j = n - 1 - j;
            } else {
                j = n - j;
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