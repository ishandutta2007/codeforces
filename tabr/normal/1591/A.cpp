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
        int now = 1;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (now == -1) {
                continue;
            }
            if (a == 0) {
                if (prev == 0) {
                    now = -1;
                }
            } else {
                if (prev == 1) {
                    now += 5;
                } else {
                    now += 1;
                }
            }
            prev = a;
        }
        cout << now << '\n';
    }
    return 0;
}