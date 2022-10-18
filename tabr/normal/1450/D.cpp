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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i]--;
            b[a[i]]++;
        }
        vector<int> ans(n);
        ans[0] = 1;
        ans[n - 1] = 1;
        for (int i = 0; i < n; i++) {
            if (b[i] != 1) {
                ans[0] = 0;
                break;
            }
        }
        if (b[0] == 0) {
            ans[n - 1] = 0;
        }
        int l = 0, r = n - 1;
        for (int i = 1; i < n; i++) {
            if (b[i - 1] != 1) {
                break;
            }
            if (a[l] == i - 1) {
                l++;
            } else if (a[r] == i - 1) {
                r--;
            } else {
                break;
            }
            if (b[i] != 0) {
                ans[n - 1 - i] = 1;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}