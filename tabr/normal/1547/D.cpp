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
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
        }
        cout << 0 << " ";
        int y = x[0];
        for (int i = 1; i < n; i++) {
            int z = 0;
            for (int j = 0; j < 30; j++) {
                if (y & (1 << j)) {
                    if (!(x[i] & (1 << j))) {
                        z |= 1 << j;
                    }
                }
            }
            cout << z << " ";
            y = z ^ x[i];
        }
        cout << '\n';
    }
    return 0;
}