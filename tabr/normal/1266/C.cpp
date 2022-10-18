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
    int h, w;
    cin >> h >> w;
    if (h == 1 && w == 1) {
        cout << 0 << '\n';
        return 0;
    }
    if (h == 1) {
        for (int j = 0; j < w; j++) {
            cout << j + 2 << " ";
        }
        cout << '\n';
        return 0;
    }
    if (w == 1) {
        for (int i = 0; i < h; i++) {
            cout << i + 2 << '\n';
        }
        return 0;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << (i + 1) * (h + 1 + j) / __gcd(i + 1, h + 1 + j) << " ";
        }
        cout << '\n';
    }
    return 0;
}