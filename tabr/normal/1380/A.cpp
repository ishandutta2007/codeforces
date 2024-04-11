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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n - 2; i++) {
            if (a[i] < a[i + 1] && a[i + 1] > a[i + 2]) {
                cout << "YES" << '\n';
                cout << i + 1 << " " << i + 2 << " " << i + 3 << '\n';
                break;
            }
            if (i == n - 3) {
                cout << "NO" << '\n';
            }
        }
    }
    return 0;
}