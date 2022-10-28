#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        bool yes = true;
        for (int i = 0; i < 3; ++i) {
            yes &= s[i] == "YES"[i] || s[i] == "yes"[i];
        }

        cout << (yes ? "YES" : "NO") << "\n";
    }
}