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
        string s;
        cin >> s;
        vector<int> a(2);
        for (int i = 0; i < s.size(); i++) {
            a[s[i] - '0']++;
        }
        if (min(a[0], a[1]) % 2 == 1) {
            cout << "DA" << '\n';
        } else {
            cout << "NET" << '\n';
        }
    }
    return 0;
}