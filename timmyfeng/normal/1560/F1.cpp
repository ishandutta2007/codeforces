#include <bits/stdc++.h>
using namespace std;

string solve(string s, int k) {
    int n = s.size(), prefix = 0;
    set<char> digits;
    for ( ; prefix < n; ++prefix) {
        digits.insert(s[prefix]);
        if ((int) digits.size() > k) {
            digits.erase(s[prefix]);
            break;
        }
    }

    if (prefix == n) {
        return s;
    } else if (s[prefix] < *--digits.end()) {
        s[prefix] = *digits.upper_bound(s[prefix]);
        for (int i = prefix + 1; i < n; ++i) {
            s[i] = *digits.begin();
        }
        return s;
    } else {
        ++s[prefix - 1];
        for (int i = prefix; i < n; ++i) {
            s[i] = '0';
        }
        return solve(s, k);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        string s;
        int k;

        cin >> s >> k;

        cout << solve(s, k) << "\n";
    }
}