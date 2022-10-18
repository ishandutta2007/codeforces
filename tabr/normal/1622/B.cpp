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
        string b;
        cin >> b;
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 0);
        sort(ans.begin(), ans.end(), [&](int i, int j) {
            if (b[i] == b[j]) {
                return a[i] > a[j];
            }
            return b[i] > b[j];
        });
        vector<int> out(n);
        for (int i = 0; i < n; i++) {
            out[ans[i]] = n - i;
        }
        for (int i = 0; i < n; i++) {
            cout << out[i] << " \n"[i == n - 1];
        }
    }
    return 0;
}