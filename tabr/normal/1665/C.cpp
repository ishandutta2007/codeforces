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
        vector<int> c(n);
        for (int i = 0; i < n - 1; i++) {
            int j;
            cin >> j;
            j--;
            c[j]++;
        }
        c.emplace_back(1);
        sort(c.rbegin(), c.rend());
        int high = n;
        int low = 0;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            int need = 0;
            for (int i = 0; i < (int) c.size(); i++) {
                if (c[i] == 0) {
                    break;
                }
                if (i + c[i] <= mid) {
                    need++;
                } else {
                    need += (i + c[i]) - mid + 1;
                }
            }
            if (need <= mid) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << '\n';
    }
    return 0;
}