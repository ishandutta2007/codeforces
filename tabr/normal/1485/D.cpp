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
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }
    int m = 32;
    vector<int> k4(m);
    for (int i = 0; i < m; i++) {
        k4[i] = i * i * i * i;
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int b = 720720;
            if ((i + j) % 2) {
                b += k4[a[i][j]];
            }
            cout << b << " ";
        }
        cout << '\n';
    }
    return 0;
}