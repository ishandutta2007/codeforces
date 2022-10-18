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
        int n, m;
        cin >> n >> m;
        vector<string> s(n);
        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }
        while (s[0] == string(m, 'E')) {
            s.erase(s.begin());
            s.emplace_back(string(m, 'E'));
        }
        while (true) {
            bool found = false;
            for (int i = 0; i < n; i++) {
                if (s[i][0] == 'R') {
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
            for (int i = 0; i < n; i++) {
                s[i].erase(s[i].begin());
                s[i] += "E";
            }
        }
        cout << (s[0][0] == 'R' ? "YES" : "NO") << '\n';
    }
    return 0;
}