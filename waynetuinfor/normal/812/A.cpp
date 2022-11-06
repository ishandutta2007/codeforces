#include <bits/stdc++.h>
using namespace std;

int l[4], r[4], s[4], p[4];
const int f[4][3] = {
    {3, 2, 1},
    {0, 3, 2},
    {1, 0, 3},
    {2, 1, 0}
};

int main() {
    for (int i = 0; i < 4; ++i) cin >> l[i] >> s[i] >> r[i] >> p[i];
    for (int i = 0; i < 4; ++i) {
        bool go = l[i] || r[i] || s[i];
        if (go && p[i]) return cout << "YES\n", 0;
    }
    for (int i = 0; i < 4; ++i) {
        if (l[i] && p[f[i][0]]) return cout << "YES\n", 0;
        if (s[i] && p[f[i][1]]) return cout << "YES\n", 0;
        if (r[i] && p[f[i][2]]) return cout << "YES\n", 0;
    }
    cout << "NO\n";
    return 0;
}