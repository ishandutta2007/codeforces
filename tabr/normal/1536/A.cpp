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
        if (*min_element(a.begin(), a.end()) < 0) {
            cout << "No" << '\n';
            continue;
        }
        cout << "Yes" << '\n';
        cout << 101 << '\n';
        for (int i = 0; i <= 100; i++) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}