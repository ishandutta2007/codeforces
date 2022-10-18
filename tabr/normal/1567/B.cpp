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
    int n = (int) 3e5 + 10;
    vector<int> x(n);
    for (int i = 1; i < n; i++) {
        x[i] = x[i - 1] ^ i;
    }
    while (tt--) {
        int a, b;
        cin >> a >> b;
        if (x[a - 1] == b) {
            cout << a << '\n';
        } else if (x[a - 1] == (a ^ b)) {
            cout << a + 2 << '\n';
        } else {
            cout << a + 1 << '\n';
        }
    }
    return 0;
}