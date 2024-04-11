#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; cin >> q;

    while (q--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;

        vector<int> prev_c(n, -1), next_a(n, n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') next_a[i] = i;
            if (s[i] == 'c') prev_c[i] = i;
        }

        for (int i = 1; i < n; ++i)
            prev_c[i] = max(prev_c[i - 1], prev_c[i]);
        for (int i = n - 2; i >= 0; --i)
            next_a[i] = min(next_a[i + 1], next_a[i]);

        bool valid = true;
        for (int i = 0, j = 0; i < n; ++i) {
            if (s[i] != 'b') continue;

            while (j < n && t[j] != 'b') ++j;
            valid &= (prev_c[i] < j && j < next_a[i]);
            ++j;
        }

        string p, q;
        for (int i = 0; i < n; ++i) {
            if (s[i] != 'b') p += s[i];
            if (t[i] != 'b') q += t[i];
        }
        valid &= (p == q);

        cout << (valid ? "YES" : "NO") << "\n";
    }
}