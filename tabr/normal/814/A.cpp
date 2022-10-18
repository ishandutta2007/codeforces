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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    if (k > 1) {
        cout << "Yes" << '\n';
    } else {
        string ans = "No";
        for (int i = 0; i < n; i++) {
            if (a[i] == 0) {
                a[i] = b[0];
            }
            if (i && a[i - 1] > a[i]) {
                ans = "Yes";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}