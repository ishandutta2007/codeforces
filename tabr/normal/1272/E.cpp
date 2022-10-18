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
    int n;
    cin >> n;
    vector<int> a(n), c(n, 1e8);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (i - a[i] >= 0) {
            if (a[i] % 2 != a[i - a[i]] % 2) {
                c[i] = 1;
            } else {
                g[i - a[i]].emplace_back(i);
            }
        }
        if (i + a[i] < n) {
            if (a[i] % 2 != a[i + a[i]] % 2) {
                c[i] = 1;
            } else {
                g[i + a[i]].emplace_back(i);
            }
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        if (c[i] == 1) {
            pq.push({1, i});
        }
    }
    while (!pq.empty()) {
        int v = pq.top().second, d = pq.top().first;
        pq.pop();
        if (c[v] < d) continue;
        for (int to : g[v]) {
            if (c[to] > c[v] + 1) {
                c[to] = c[v] + 1;
                pq.push({c[to], to});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (c[i] >= 1e7) {
            c[i] = -1;
        }
        cout << c[i] << " ";
    }
    cout << '\n';
    return 0;
}