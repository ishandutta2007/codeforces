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
        int n, m, x;
        cin >> n >> m >> x;
        vector<int> h(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.rbegin(), order.rend(), [&](int i, int j) { return h[i] < h[j]; });
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < m; i++) {
            pq.emplace(0, i);
        }
        vector<int> ans(n);
        for (int i : order) {
            auto p = pq.top();
            pq.pop();
            p.first += h[i];
            ans[i] = p.second + 1;
            pq.emplace(p);
        }
        int mn = pq.top().first;
        for (int i = 0; i < m - 1; i++) {
            pq.pop();
        }
        int mx = pq.top().first;
        if (mx - mn <= x) {
            cout << "YES" << '\n';
            for (int i : ans) {
                cout << i << " ";
            }
            cout << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
    return 0;
}