#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, k; cin >> n >> k;

        map<int, int> first, last;
        for (int i = 0; i < n; ++i) {
            int u; cin >> u;
            if (!first.count(u)) {
                first[u] = i;
            }
            last[u] = i;
        }

        while (k--) {
            int a, b; cin >> a >> b;
            cout << (first.count(a) && first.count(b) && first[a] < last[b] ? "YES" : "NO") << "\n";
        }
    }
}