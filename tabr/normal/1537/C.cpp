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
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        sort(h.begin(), h.end());
        if (n == 2) {
            cout << h[0] << " " << h[1] << '\n';
            continue;
        }
        int id = -1;
        int dif = (int) 2e9;
        for (int i = 0; i < n - 1; i++) {
            if (h[i + 1] - h[i] < dif) {
                dif = h[i + 1] - h[i];
                id = i;
            }
        }
        rotate(h.begin(), h.begin() + id + 1, h.end());
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << h[i];
        }
        cout << '\n';
    }
    return 0;
}