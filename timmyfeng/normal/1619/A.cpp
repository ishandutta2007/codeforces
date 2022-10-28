#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        cout << (s.size() % 2 == 0 && s.substr(0, s.size() / 2) == s.substr(s.size() / 2) ? "YES" : "NO") << "\n";
    }
}