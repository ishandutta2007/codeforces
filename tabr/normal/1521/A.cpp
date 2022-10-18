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
        long long a, b;
        cin >> a >> b;
        if (b == 1) {
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
        cout << a * b << " " << a << " " << a * b + a << '\n';
    }
    return 0;
}