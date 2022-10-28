#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans = {0};
        int i = 1;
        for ( ; i * i <= n; ++i) {
            if (n < (i + 1) * (n / i)) {
                ans.push_back(i);
            }
        }
        for (--i ; i; --i) {
            if (n / i != ans.back()) {
                ans.push_back(n / i);
            }
        }
        cout << ans.size() << '\n';
        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << '\n';
    }
}