#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(15);
    int n, m;
    cin >> n >> m;
    vector<long double> ans(2);
    for (int z = 0; z < 2; z++) {
        if (n == 1) {
            swap(n, m);
            continue;
        }
        vector<pair<long double, long double>> q;
        q.emplace_back(0, -1);
        for (int i = 0; i < m; i++) {
            q.emplace_back(i, n);
            q.emplace_back(i + 1, 0);
        }
        q.emplace_back(m, -1);
        cout << "? " << q.size() << endl;
        for (auto [x, y] : q) {
            if (!z) {
                swap(x, y);
            }
            cout << x << " " << y << endl;
        }
        long double s;
        cin >> s;
        s *= 2 * n;
        s += 1;
        s /= 2;
        ans[z] = n - s;
        swap(n, m);
    }
    cout << "! " << ans[0] << " " << ans[1] << endl;
    return 0;
}