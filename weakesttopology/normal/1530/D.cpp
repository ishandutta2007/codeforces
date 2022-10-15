#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> E(n);
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            E[a[i]].push_back(i);
        }
        vector<int> endpoints, startpoints;
        for (int i = 0; i < n; ++i) {
            if (empty(E[i])) startpoints.push_back(i);
            if (size(E[i]) <= 1) continue;
            sort(begin(E[i]), end(E[i]), [&](int i, int j) { return empty(E[i]) > empty(E[j]); });
            endpoints.insert(end(endpoints), begin(E[i]) + 1, end(E[i]));
            E[i].resize(1);
        }
        vector<int> b(n);
        int k = 0;
        for (int i = 0; i < n; ++i) {
            if (not empty(E[i])) {
                b[E[i][0]] = i;
                ++k;
            }
        }
        assert(size(endpoints) == size(startpoints));
        int l = (int)size(startpoints);
        for (int j = 0; j < l; ++j) {
            if (endpoints[j] == startpoints[j]) {
                swap(startpoints[j], startpoints[(j + 1) % l]);
            }
        }
        for (int j = 0; j < l; ++j) {
            b[endpoints[j]] = startpoints[j];
        }
        cout << k << '\n';
        for (int i = 0; i < n; ++i) {
            cout << b[i] + 1 << "\n "[i + 1 < n];
        }
    }
    exit(0);
}