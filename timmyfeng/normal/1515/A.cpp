#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, x;
        cin >> n >> x;

        vector<int> a(n);
        for (auto &i : a) {
            cin >> i;
        }

        sort(a.begin(), a.end());

        if (accumulate(a.begin(), a.end(), 0) == x) {
            cout << "NO\n";
            continue;
        }

        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            if (x == a[i]) {
                cout << a[i + 1] << " " << a[i] << " ";
                x -= a[i + 1] + a[i];
                ++i;
            } else {
                x -= a[i];
                cout << a[i] << " ";
            }
        }
        cout << "\n";
    }
}