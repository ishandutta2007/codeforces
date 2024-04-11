#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    bool one = false;
    for (int i = 0; i < n; ++i) {
        if (s.substr(i, 2) == "11") {
            one = true;
        } else if (one && s.substr(i, 2) == "00") {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}