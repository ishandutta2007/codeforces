#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main() {
    vector<int> all;
    for (int i = 1; i <= 10; ++i) {
        for (int j = 0; j <= i; ++j) {
            vector<int> v;
            for (int k = 0; k < j; ++k) v.push_back(4);
            for (int k = 0; k < i - j; ++k) v.push_back(7);
            do {
                int t = 0, c = 1;
                for (int k : v) t += c * k, c *= 10;
                all.push_back(t);
            } while (next_permutation(v.begin(), v.end()));
        }
    }
    int l, r; cin >> l >> r;
    sort(all.begin(), all.end());
    int now = *lower_bound(all.begin(), all.end(), l);
    int ans = 0, prv = l;
    while (prv <= r) {
        // cout << prv << ' ' << now << endl;
        ans += (min(now, r) - prv + 1) * now;
        prv = now + 1;
        if (prv > r) break;
        now = *lower_bound(all.begin(), all.end(), now + 1);
    }
    cout << ans << endl;
}