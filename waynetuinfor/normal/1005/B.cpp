#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t; cin >> s >> t;
    int ans = s.size() + t.size();
    for (int i = s.size() - 1, j = t.size() - 1, c = 0; i >= 0 && j >= 0; --i, --j, ++c) {
        if (s[i] == t[j]) ans = min(ans, (int)s.size() + (int)t.size() - 2 * (c + 1));
        else break;
    }
    cout << ans << endl;
}