#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q; cin >> n >> q;

    vector<long long> p(n);
    for (auto &i : p) cin >> i;

    sort(p.begin(), p.end());

    vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + p[i];

    while (q--) {
        int x, y; cin >> x >> y;
        cout << sum[n - (x - y)] - sum[n - x] << "\n";
    }
}