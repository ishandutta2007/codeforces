#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    int p = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '*') p = i;
    }
    if (p == -1) {
        if (s == t) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    if (n > m + 1) {
        cout << "NO" << endl;
        return 0;
    }
    bool ans = true;
    for (int i = 0; i < p; ++i) ans &= s[i] == t[i];
    for (int i = s.size() - 1, j = t.size() - 1; i > p; --i, --j) ans &= s[i] == t[j];
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}