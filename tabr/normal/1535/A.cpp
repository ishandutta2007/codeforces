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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int e = max(a, b), f = max(c, d);
        vector<int> x = {a, b, c, d};
        sort(x.begin(), x.end());
        if (e > f) {
            swap(e, f);
        }
        if (x[2] == e && x[3] == f) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}