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
        int a = 0;
        for (int i = 0; i < n; i++) {
            int b;
            cin >> b;
            a |= b;
        }
        cout << a << '\n';
    }
    return 0;
}