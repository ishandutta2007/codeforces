#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <array>
#include <set>

using namespace std;


int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        // inf check
        long long pos = 0LL, neg = 0LL;
        for (int i = 0; i < n; i++) {
            pos += a[i];
            neg += a[i];
            if (i == 0) pos += (n - 2) * 1LL * a[0];
            if (i == n - 1) neg += (n - 2) * 1LL * a[n - 1];
        }
        if (pos > 0 || neg < 0) {
            cout << "INF" << "\n";
            continue;
        }
        long long suf = 0LL, pref = accumulate(a.begin(), a.end(), 0LL);
        long long ans = -1e18;
        for (int i = n - 1; i >= 0; i--) {
            // t = -a[i]
            int curr_t = -a[i];
            suf += a[i];
            pref -= a[i];
            long long curr = (a[0] + curr_t) * 1LL * (suf + (n - i) * 1LL * curr_t);
            curr += (a[n - 1] + curr_t) * 1LL * (pref + i * 1LL * curr_t);
            curr -= ((a[0] + curr_t) * 1LL * (a[n - 1] + curr_t) - curr_t * 1LL * curr_t);
            curr -= n * 1LL * curr_t * 1LL * curr_t;
            ans = max(ans, curr);
        }
        cout << ans << "\n";
    }
}