#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        string s; cin >> s;

        if (s.size() == 2) cout << s[1] << "\n";
        else cout << *min_element(s.begin(), s.end()) << "\n";
    }
}