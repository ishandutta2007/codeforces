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
        for (int i = 0; i < n - 1; i++) {
            while (a[i] > 0 && k > 0) {
                k--;
                a[i]--;
                a[n - 1]++;
            }
        }
        for (int i : a) {
            cout << i << " ";
        }
        cout << '\n';
    }
    return 0;
}