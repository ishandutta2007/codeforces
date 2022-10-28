#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector pos(n, vector<int>());
        for (int i = 0; i < n; ++i) {
            int a; cin >> a; --a;
            pos[a].push_back(i % 2);
        }

        for (int i = 0; i < n; ++i) {
            int zero = 0, one = 0;
            for (auto j : pos[i]) {
                if (j == 0) {
                    zero = max(zero, one + 1);
                } else {
                    one = max(one, zero + 1);
                }
            }
            cout << max(zero, one) << " ";
        }
        cout << "\n";
    }
}