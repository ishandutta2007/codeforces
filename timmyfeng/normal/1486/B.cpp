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

        vector<int> x(n), y(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        if (n % 2 == 1) {
            cout << 1 << "\n";
        } else {
            int xl = x[n / 2 - 1], xr = x[n / 2];
            int yl = y[n / 2 - 1], yr = y[n / 2];
            cout << (long long) (xr - xl + 1) * (yr - yl + 1) << "\n";
        }
    }
}