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
        long long t = accumulate(a.begin(), a.end(), 0LL);
        for (int i = 0; i < n; i++) {
            a[i] %= k;
        }
        t -= accumulate(a.begin(), a.end(), 0LL);
        vector<int> c(k);
        for (int i = 0; i < n; i++) {
            c[a[i]]++;
        }
        int high = k - 1;
        int low = 1;
        while (high >= low) {
            if (high + low < k) {
                low++;
                continue;
            }
            int d = min(c[high], c[low]);
            if (high == low) {
                d /= 2;
            }
            c[high] -= d;
            c[low] -= d;
            t += 1LL * d * k;
            if (high == low) {
                break;
            }
            if (c[low] == 0) {
                low++;
            }
            if (c[high] == 0) {
                high--;
            }
        }
        cout << t / k << '\n';
    }
    return 0;
}