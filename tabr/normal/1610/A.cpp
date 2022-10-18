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
        if (max(n, m) == 1) {
            cout << 0 << '\n';
        } else if (min(n, m) == 1) {
            cout << 1 << '\n';
        } else {
            cout << 2 << '\n';
        }
    }
    return 0;
}