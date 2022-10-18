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
        int h, w, x, y;
        cin >> h >> w >> x >> y;
        x--, y--;
        cout << 1 << " " << 1 << " " << h << " " << w << '\n';
    }
    return 0;
}