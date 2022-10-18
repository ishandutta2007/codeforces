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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        for (int i = 0; i < k; i++) {
            a[i + k] /= a[i];
            a[i] = 0;
        }
        cout << accumulate(a.begin(), a.end(), 0) << '\n';
    }
    return 0;
}