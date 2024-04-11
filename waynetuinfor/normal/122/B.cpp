#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int mx = 0;
    string ans = "";
    for (int i = 0; i < s.size(); ++i) {
        for (int j = i; j < s.size(); ++j) {
            string t = s.substr(i, j - i + 1);
            bool ok = true;
            for (int k = 0; k < t.size(); ++k) ok &= (t[k] == '4' || t[k] == '7');
            if (!ok) continue;
            int c = 0;
            for (int k = 0; k <= s.size() - t.size(); ++k) {
                if (s.substr(k, t.size()) == t) ++c;
            }
            if (c > mx) mx = c, ans = t;
            else if (c == mx) ans = min(ans, t);
        }
    }
    if (ans.size() == 0) cout << "-1" << endl;
    else cout << ans << endl;
}