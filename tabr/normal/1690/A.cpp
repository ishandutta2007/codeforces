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
        int x = n / 3 - 1;
        int y = n / 3 - 1;
        int z = n / 3 - 1;
        x += 1;
        y += 2;
        while (x + y + z < n) {
            if (x + y + z < n) {
                y++;
            }
            if (x + y + z < n) {
                x++;
            }
            if (x + y + z < n) {
                z++;
            }
        }
        cout << x << " " << y << " " << z << '\n';
    }
    return 0;
}