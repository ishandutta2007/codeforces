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
        if (n == 1) {
            cout << "a" << '\n';
        } else if (n % 2 == 0) {
            cout << string(n / 2, 'a') + "b" + string(n / 2 - 1, 'a') << '\n';
        } else {
            cout << string(n / 2, 'a') + "bc" + string(n / 2 - 1, 'a') << '\n';
        }
    }
    return 0;
}