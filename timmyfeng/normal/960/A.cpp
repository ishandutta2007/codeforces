#include <bits/stdc++.h>
using namespace std;

int f[3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    bool ok = true;
    for (int i = 0; i < (int) s.size(); ++i) {
        ok &= (i == 0 || s[i] >= s[i - 1]);
        ++f[s[i] - 'a'];
    }

    ok &= (f[0] == f[2] || f[1] == f[2]);

    for (auto i : f) {
        ok &= (i > 0);
    }

    cout << (ok ? "YES" : "NO") << "\n";
}