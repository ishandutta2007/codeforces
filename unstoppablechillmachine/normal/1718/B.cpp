#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef PC
    freopen("input.txt", "r", stdin);
#endif
    int cur = 1, prv = 1, sum = 2;
    set<int> fib_sums = {1, 2};
    map<int, int> val_by_sum;
    val_by_sum[1] = val_by_sum[2] = 1;
    for (int i = 3;; i++) {
        int new_val = cur + prv;
        prv = cur;
        cur = new_val;
        sum += cur;
        fib_sums.insert(sum);
        val_by_sum[sum] = cur;
        //cout << sum * 1.0 / cur << '\n';
        if (cur > 1e9) {
            break;
        }
    }
    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;
        vector<int> a(k);
        int sum = 0;
        for (int i = 0; i < k; i++) {
            cin >> a[i];
            sum += a[i];
        }
        if (!fib_sums.count(sum)) {
            cout << "NO\n";
            continue;
        }
        int prv = k;
        bool ok = true;
        while (sum) {
            pair<int, int> best = {-1, k};
            for (int i = 0; i < k; i++) {
                if (i != prv && a[i] >= val_by_sum[sum]) {
                    best = max(best, {a[i], i});
                }
            }
            if (best.second == k) {
                ok = false;
                break;
            }
            a[best.second] -= val_by_sum[sum];
            //cout << best.second << ' ' << a[best.second] << '\n';
            sum -= val_by_sum[sum];
            prv = best.second;
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}