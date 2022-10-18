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
        long long n;
        cin >> n;
        if (n % 2 == 1) {
            n++;
        }
        if (n < 6) {
            n = 6;
        }
        cout << n * 5 / 2 << '\n';
    }
    return 0;
}