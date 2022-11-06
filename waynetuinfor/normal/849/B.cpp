#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
const double inf = 1e9 + 1;
double y[maxn];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> y[i];
    for (int i = 2; i <= n; ++i) {
        double m = (y[i] - y[1]) / (double)(i - 1);
        double k = y[0] - m;
        int a = 0, b = 0;
        vector<int> inv;
        bool ans = true;
        ++a;
        // cout << "m = " << m << " k = " << k << endl;
        for (int j = 2; j <= n; ++j) {
            if (j == i) continue;
            double mi = (y[j] - y[1]) / (double)(j - 1);
            double ki = y[j] - mi * j;
            if (mi != m) inv.push_back(j);
            else ++a;
        }
        if (inv.size() == 0) continue;
        if (inv.size() == 1) return cout << "Yes" << endl, 0;
        double mn = (y[inv[1]] - y[inv[0]]) / (double)(inv[1] - inv[0]);
        double kn = y[inv[1]] - mn * inv[1];
        if (mn != m) ans = false;
        if (kn == k) ans = false;
        for (int j = 2; j < inv.size(); ++j) {
            double mm = (y[inv[j]] - y[inv[0]]) / (double)(inv[j] - inv[0]);
            // cout << "mm = " << mm << endl;
            if (mm != mn) ans = false;
            if (mm != m) ans = false;
        }
        // for (int j : inv) cout << j << ' '; cout << endl;
        // cout << "i = " << i << endl;
        if (ans) return cout << "Yes" << endl, 0;
    }
    double m = (y[3] - y[2]);
    for (int j = 3; j <= n; ++j) {
        double mk = (y[j] - y[2]) / (double)(j - 2);
        if (mk != m) return cout << "No" << endl, 0;
    }
    double mm = (y[2] - y[1]);
    if (mm == m) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    return 0;
}