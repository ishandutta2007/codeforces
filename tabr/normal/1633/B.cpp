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
        int n = (int) s.size();
        vector<int> a(2);
        for (int i = 0; i < n; i++) {
            a[s[i] - '0']++;
        }
        if (a[0] != a[1]) {
            cout << min(a[0], a[1]) << '\n';
        } else {
            cout << a[0] - 1 << '\n';
        }
    }
    return 0;
}