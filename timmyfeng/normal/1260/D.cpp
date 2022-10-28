#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n, k, t;
    cin >> m >> n >> k >> t;
    vector<int> ps(2e5 + 1);
    while (m--) {
        int a;
        cin >> a;
        ++ps[a];
    }
    vector<tuple<int, int, int>> trap(k * 2);
    for (int i = 0; i < k; ++i) {
        int l, r, d;
        cin >> l >> r >> d;
        trap[i * 2] = make_tuple(l - 1, false, d);
        trap[i * 2 + 1] = make_tuple(r, true, d);
    }

    sort(trap.begin(), trap.end());
    for (int i = 2e5 - 1; i; --i) {
        ps[i] += ps[i + 1];
    }

    int l = 1, r = 2e5;
    while (l <= r) {
        int mi = (l + r) / 2;
        int len = 0, ct = 0, prev = 0;
        for (int i = 0; i < k * 2; ++i) {
            if (get<2>(trap[i]) <= mi) continue;
            if (ct) {
                len += get<0>(trap[i]) - prev;
            }
            if (get<1>(trap[i])) {
                --ct;
            } else {
                ++ct;
            }
            prev = get<0>(trap[i]);
        }
        if (n + 1 + 2 * len <= t) {
            r = mi - 1;
        } else {
            l = mi + 1;
        }
    }
    cout << ps[l] << '\n';
}