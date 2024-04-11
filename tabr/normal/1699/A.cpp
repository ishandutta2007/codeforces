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
        if (n % 2 == 0) {
            cout << n / 2 << " " << 0 << " " << 0 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}