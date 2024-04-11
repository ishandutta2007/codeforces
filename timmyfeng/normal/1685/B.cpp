#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int a, b, ab, ba; cin >> a >> b >> ab >> ba;
        string s; cin >> s;
        int n = s.size();

        a += ab + ba, b += ab + ba;
        if (count(s.begin(), s.end(), 'A') != a || count(s.begin(), s.end(), 'B') != b) {
            cout << "NO\n";
            continue;
        }

        int units = 0;
        vector<int> ab_units, ba_units;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && (j == i || s[j] != s[j - 1])) ++j;

            if ((j - i) % 2) {
                units += (j - i) / 2;
            } else {
                (s[i] == 'A' ? ab_units : ba_units).push_back((j - i) / 2);
            }
        }

        sort(ab_units.begin(), ab_units.end());
        sort(ba_units.begin(), ba_units.end());

        for (auto i : ab_units) {
            if (i <= ab) {
                ab -= i;
            } else {
                units += i - 1;
            }
        }

        for (auto i : ba_units) {
            if (i <= ba) {
                ba -= i;
            } else {
                units += i - 1;
            }
        }

        cout << (units >= ab + ba ? "YES" : "NO") << "\n";
    }
}