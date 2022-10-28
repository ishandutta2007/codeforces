#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> dsu(n, -1);

        auto find = [&](int a) {
            while (dsu[a] >= 0) a = dsu[a];
            return a;
        };

        auto unite = [&](int a, int b) {
            a = find(a), b = find(b);
            if (a == b) return;
            if (-dsu[a] < -dsu[b]) swap(a, b);
            dsu[a] += dsu[b];
            dsu[b] = a;
        };

        vector<int> occ(n);
        for (int i = 0; i < n; ++i) {
            int a, b; cin >> a >> b; --a, --b;
            ++occ[a], ++occ[b];
            unite(a, b);
        }

        if (count(occ.begin(), occ.end(), 2) != n) {
            cout << "NO\n";
            continue;
        }

        bool answer = true;
        for (int i = 0; i < n; ++i) {
            if (find(i) == i) {
                answer &= -dsu[i] % 2 == 0;
            }
        }

        cout << (answer ? "YES" : "NO") << "\n";
    }
}