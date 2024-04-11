#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        string ans = "Yes";
        for (int i = 1; i < (int) s.size(); ++i) {
            if (s[i - 1] + 1 != s[i]) {
                ans = "No";
            }
        }

        cout << ans << "\n";
    }
}