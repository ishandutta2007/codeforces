#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int l = -1, r = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '1') {
                if (l == -1) l = i;
                r = i;
            }
        }
        if (l == -1) {
            cout << 0 << "\n";
            continue;
        }
        int res = 0;
        for (int i = l; i <= r; ++i) res += s[i] == '0';
        cout << res << "\n";
    }
}