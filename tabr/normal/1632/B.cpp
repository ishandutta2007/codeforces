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
        iota(p.begin(), p.end(), 0);
        for (int i = n - 1; i > 0; i--) {
            if (i == 1 || __builtin_clz(i) != __builtin_clz(i - 1)) {
                reverse(p.begin(), p.begin() + i);
                break;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << p[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}