#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 1, len = 0;
        for (auto c : s) {
            if (c == 'L') {
                ans = max(ans, ++len + 1);
            } else {
                len = 0;
            }
        }
        cout << ans << '\n';
    }
}