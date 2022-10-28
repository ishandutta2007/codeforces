#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        bool ok = true;
        int c = -1, d = -1;
        for (int i = 0; i < n - 1; ++i) {
            int &e = a[i] <= a[i + 1] ? c : d;
            if (e == -1) {
                e = abs(a[i + 1] - a[i]);
            } else {
                ok &= abs(a[i + 1] - a[i]) == e;
            }
        }
        ok &= c != 0 || d == -1;

        if (!ok) {
            cout << -1 << "\n";
        } else if (c == -1 || d == -1) {
            cout << 0 << "\n";
        } else {
            for (int i = 0; i < n - 1; ++i) {
                ok &= (a[i] + c) % (c + d) == a[i + 1];
            }
            ok &= *max_element(a.begin(), a.end()) < c + d;

            if (ok) {
                cout << c + d << " " << c << "\n";
            } else {
                cout << -1 << "\n";
            }
        }
    }
}