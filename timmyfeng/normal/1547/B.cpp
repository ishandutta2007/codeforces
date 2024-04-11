#include <bits/stdc++.h>
using namespace std;

bool is_alpha(string s) {
    if (s.empty()) {
        return true;
    } else if (s[0] == 'a' + s.size() - 1) {
        return is_alpha(s.substr(1));
    } else if (s.back() == 'a' + s.size() - 1) {
        return is_alpha(s.substr(0, s.size() - 1));
    } else {
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        cout << (is_alpha(s) ? "Yes" : "No") << "\n";
    }
}