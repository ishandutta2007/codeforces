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
        vector<int> a(n), b(n);
        int c = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            c += a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            c -= b[i];
        }
        c = abs(c);
        set<int> s;
        for (int i = 0; i < n; i++) {
            s.emplace(a[i] * 2 + b[i]);
        }
        if (s.count(2) && s.count(1)) {
            c++;
        }
        cout << c << '\n';
    }
    return 0;
}