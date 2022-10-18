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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> b;
        if (n == 2) {
            if (a[0] + a[1] == 2) {
                b = a;
            } else {
                b.emplace_back(0);
            }
        } else if (n == 5) {
            int c = a[0] + a[1] + a[2];
            if (c <= 1) {
                b.emplace_back(0);
                b.emplace_back(0);
            } else {
                b.emplace_back(1);
                b.emplace_back(1);
            }
            c = a[3] + a[4];
            if (c == 2) {
                b.emplace_back(1);
                b.emplace_back(1);
            } else {
                b.emplace_back(0);
            }
        } else {
            for (int i = 0; i + 2 < n; i += 3) {
                int c = a[i] + a[i + 1] + a[i + 2];
                if (c <= 1) {
                    b.emplace_back(0);
                    b.emplace_back(0);
                } else {
                    b.emplace_back(1);
                    b.emplace_back(1);
                }
            }
        }
        cout << b.size() << '\n';
        for (int i : b) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}