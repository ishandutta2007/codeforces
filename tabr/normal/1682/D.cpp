#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ones = (int) count(s.begin(), s.end(), '1');
        if (ones % 2 == 1 || ones == 0) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        vector<int> c;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                c.emplace_back(i);
            } else {
                cout << i + 1 << " " << (i + 1) % n + 1 << '\n';
            }
        }
        for (int i = 0; i + 1 < (int) c.size(); i++) {
            cout << (c[i] + 1) % n + 1 << " " << (c.back() + 1) % n + 1 << '\n';
        }
    }
    return 0;
}