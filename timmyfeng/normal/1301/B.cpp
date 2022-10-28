#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& i : a) {
            cin >> i;
        }

        int mx = 0, mn = 1e9;
        for (int i = 0; i < n; ++i) {
            if (a[i] == -1) {
                if (i && a[i - 1] != -1) {
                    mx = max(mx, a[i - 1]);
                    mn = min(mn, a[i - 1]);
                }
                if (i < n - 1 && a[i + 1] != -1) {
                    mx = max(mx, a[i + 1]);
                    mn = min(mn, a[i + 1]);
                }
            }
        }

        for (auto& i : a) {
            if (i == -1) {
                i = (mx + mn) / 2;
            }
        }

        int k = 0;
        for (int i = 1; i < n; ++i) {
            k = max(k, abs(a[i] - a[i - 1]));
        }

        cout << k << ' ' << (mx + mn) / 2 << '\n';
    }
}