#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<int> a(n);
        for (auto &i : a) cin >> i;

        ranges::sort(a);

        vector<int> weight_classes;
        for (int i = 0, j = 0; i < n; i = j) {
            while (j < n && a[j] == a[i]) ++j;
            weight_classes.push_back(j - i);
        }

        int ans = INT_MAX;
        for (int i = 1; i < 2 * n; i *= 2) {
            for (int j = 1; j < 2 * n; j *= 2) {
                int division = 0, size = 0;

                for (auto k : weight_classes) {
                    if (division == 0) {
                        if (size + k <= i) size += k;
                        else ++division, size = 0;
                    }

                    if (division == 1) {
                        if (size + k <= j) size += k;
                        else ++division, size = 0;
                    }

                    if (division == 2) size += k;
                }

                if (division < 2) size = 0;

                ans = min(ans, i + j + (int) bit_ceil((unsigned) size) - n);
            }
        }

        cout << ans << "\n";
    }
}