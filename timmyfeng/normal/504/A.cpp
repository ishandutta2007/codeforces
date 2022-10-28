#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> leaf, degree(n), sum(n);
    for (int i = 0; i < n; ++i) {
        cin >> degree[i] >> sum[i];
        if (degree[i] == 1) {
            leaf.push_back(i);
        }
    }

    cout << accumulate(degree.begin(), degree.end(), 0) / 2 << "\n";

    while (!leaf.empty()) {
        int u = leaf.back();
        leaf.pop_back();

        if (degree[u] > 0) {
            cout << u << " " << sum[u] << "\n";
            if (--degree[sum[u]] == 1) {
                leaf.push_back(sum[u]);
            }
            sum[sum[u]] ^= u;
        }
    }
}