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
        int n, m;
        cin >> n >> m;
        vector<tuple<int, int, int>> x(n);
        for (int i = 0; i < n; i++) {
            cin >> get<0>(x[i]);
            get<2>(x[i]) = i;
        }
        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == 'R') {
                get<1>(x[i]) = 1;
            }
        }
        sort(x.begin(), x.end());
        vector<int> ans(n, -1);
        stack<pair<int, int>> odd, even;
        vector<deque<pair<int, int>>> deq(2);
        for (auto [i, j, k] : x) {
            if (j == 1) {
                deq[i % 2].emplace_front(i, k);
            } else {
                if (!deq[i % 2].empty()) {
                    auto [ii, kk] = deq[i % 2].front();
                    deq[i % 2].pop_front();
                    ans[k] = ans[kk] = (i - ii) / 2;
                } else {
                    deq[i % 2].emplace_front(-i, k);
                }
            }
        }
        for (int j = 0; j < 2; j++) {
            while ((int)deq[j].size() > 1) {
                auto [i0, k0] = deq[j].front();
                deq[j].pop_front();
                auto [i1, k1] = deq[j].front();
                deq[j].pop_front();
                ans[k0] = ans[k1] = (2 * m - i0 - i1) / 2;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}