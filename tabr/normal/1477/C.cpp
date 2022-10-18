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
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<int> ok(n);
    vector<int> p(n);
    ok[0] = 1;
    for (int i = 1; i < n; i++) {
        long long d = 0;
        int q = -1;
        for (int j = 0; j < n; j++) {
            if (!ok[j] && d < (x[p[i - 1]] - x[j]) * (x[p[i - 1]] - x[j]) + (y[p[i - 1]] - y[j]) * (y[p[i - 1]] - y[j])) {
                d = (x[p[i - 1]] - x[j]) * (x[p[i - 1]] - x[j]) + (y[p[i - 1]] - y[j]) * (y[p[i - 1]] - y[j]);
                q = j;
            }
        }
        p[i] = q;
        ok[q] = 1;
    }
    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " ";
    }
    cout << '\n';
    return 0;
}