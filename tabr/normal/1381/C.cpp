#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> b(n);
        vector<int> cnt(n + 1);
        y -= x;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            b[i]--;
            cnt[b[i]]++;
        }
        int c = -1;
        for (int i = 0; i < n + 1; i++) {
            if (cnt[i] == 0) {
                c = i;
                break;
            }
        }
        vector<int> same(n + 1);
        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < n + 1; i++) {
            pq.emplace(cnt[i], i);
        }
        for (int loop = 0; loop < x; loop++) {
            int s, t;
            tie(s, t) = pq.top();
            pq.pop();
            same[t]++;
            if (s != 1) {
                pq.emplace(s - 1, t);
            }
        }
        int s = n - x - pq.top().first;
        s = min(s * 2, n - x);
        if (s < y) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        vector<int> a(n, c);
        for (int i = 0; i < n; i++) {
            if (same[b[i]] > 0) {
                same[b[i]]--;
                a[i] = b[i];
            }
        }
        int mx = pq.top().first;
        vector<int> v;
        vector<int> id(n + 1, -1);
        while (!pq.empty()) {
            int p, q;
            tie(p, q) = pq.top();
            pq.pop();
            id[q] = v.size();
            for (int i = 0; i < p; i++) {
                v.emplace_back(q);
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == c && y > 0) {
                int j = id[b[i]];
                if (v[(j + mx) % v.size()] == v[j]) {
                    continue;
                }
                y--;
                a[i] = v[(j + mx) % v.size()];
                id[b[i]]++;
            }
        }
        for (int i : a) {
            cout << i + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}