#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
            cout << -1 << endl;
        } else {
            string s(n, '2');
            s[n - 1] = '3';
            if ((n - 1) % 3 == 0) {
                s[n - 2] = '3';
            }
            cout << s << endl;
        }
    }
    return 0;
}