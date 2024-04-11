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
        vector<int> p(n);
        p[n - 1] = n;
        p[n - 2] = n - 1;
        p[n - 3] = 1;
        for (int i = 0; i < n - 3; i++) {
            p[i] = i + 2;
        }
        reverse(p.begin(), p.begin() + n - 3);
        if (n % 2 == 1) {
            swap(p[0], p[1]);
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}