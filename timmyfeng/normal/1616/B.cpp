#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        string s;
        cin >> n >> s;

        if (n == 1) {
            cout << s << s << "\n";
        } else if (s[0] == s[1]) {
            cout << s[0] << s[0] << "\n";
        } else {
            int i = 0;
            while (i + 1 < n && s[i + 1] <= s[i]) ++i;
            for (int j = 0; j <= i; ++j) cout << s[j];
            for (int j = i; j >= 0; --j) cout << s[j];
            cout << "\n";
        }
    }
}