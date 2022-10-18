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
        vector<long long> a(n + 1, -1);
        a[0] = 1;
        long long sum = 1;
        for (int i = 1; i <= n; i++) {
            a[i] = sum;
            sum += a[i];
            if (a[i] > k) {
                break;
            }
        }
        if (a[n] != -1 && a[n] < k) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j = i; j < n; j++) {
                cur += a[n - 1 - j];
                if (a[n - 1 - j] == -1 || cur >= k) {
                    for (int l = j; l >= i; l--) {
                        cout << l + 1 << " ";
                    }
                    i = j;
                    k -= cur - a[n - 1 - j];
                    break;
                }
            }
        }
        cout << '\n';
    }
    return 0;
}