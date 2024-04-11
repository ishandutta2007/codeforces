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
        int h, w;
        cin >> h >> w;
        vector<int> a;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int k = max(i, h - 1 - i) + max(j, w - 1 - j);
                a.emplace_back(k);
            }
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < h * w; i++) {
            cout << a[i] << " \n"[i == h * w - 1];
        }
    }
    return 0;
}