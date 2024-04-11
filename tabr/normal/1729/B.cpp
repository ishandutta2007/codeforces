#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string ans;
        int i = n - 1;
        while (i >= 0) {
            if (s[i] == '0') {
                i -= 3;
                int t = 10 * (s[i + 1] - '0') + (s[i + 2] - '0') - 1;
                ans += (char) ('a' + t);
            } else {
                i -= 1;
                ans += (char) ('a' + s[i + 1] - '0' - 1);
            }
        }
        reverse(ans.begin(), ans.end());
        cout << ans << "\n";
    }
    return 0;
}