#include <bits/stdc++.h>
using namespace std;

bool check(string s, char c) {
    for (int i = 1; i < (int) s.size(); ++i) {
        if (s[i] == s[i - 1] && s[i] == c) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool ok = false;
        for (int i = 0; i <= (int) s.size(); ++i) {
            ok |= check(s.substr(0, i), '1') && check(s.substr(i), '0');
        }

        cout << (ok ? "YES" : "NO") << "\n";
    }
}