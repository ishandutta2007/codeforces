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
        int inf = (int) 2e9;
        vector<int> ans(n, inf);
        vector<pair<int, int>> a(k);
        for (int i = 0; i < k; i++) {
            cin >> a[i].first;
            a[i].first--;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < k; i++) {
            cin >> a[i].second;
            ans[a[i].first] = a[i].second;
            pq.emplace(a[i].second, a[i].first);
        }
        while (!pq.empty()) {
            auto [exp, i] = pq.top();
            pq.pop();
            if (ans[i] != exp) {
                continue;
            }
            if (i != 0 && ans[i - 1] > ans[i] + 1) {
                ans[i - 1] = ans[i] + 1;
                pq.emplace(ans[i - 1], i - 1);
            }
            if (i != n - 1 && ans[i + 1] > ans[i] + 1) {
                ans[i + 1] = ans[i] + 1;
                pq.emplace(ans[i + 1], i + 1);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    return 0;
}