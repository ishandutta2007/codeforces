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
        long long k;
        cin >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        string ans = "NO";
        for (int i = 0; i < n; i++) {
            long long b = k + a[i];
            if (binary_search(a.begin(), a.end(), b)) {
                ans = "YES";
            }
        }
        cout << ans << '\n';
    }
    return 0;
}