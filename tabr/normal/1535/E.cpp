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
    int tt;
    cin >> tt;
    vector<long long> a(tt + 1), c(tt + 1);
    vector<vector<int>> p(tt + 1, vector<int>(20, -1));
    cin >> a[0] >> c[0];
    for (int z = 1; z <= tt; z++) {
        int id;
        cin >> id;
        if (id == 1) {
            cin >> p[z][0] >> a[z] >> c[z];
            for (int i = 1; i < 20; i++) {
                p[z][i] = p[p[z][i - 1]][i - 1];
                if (p[z][i] == -1) {
                    break;
                }
            }
        } else {
            int v;
            long long w;
            cin >> v >> w;
            // v--;
            long long ww = w;
            // debug(v, p.size());
            int q = v;
            int j = 0;
            for (int i = 19; i >= 0; i--) {
                // debug(q);
                if (p[q][i] != -1 && a[p[q][i]] > 0) {
                    q = p[q][i];
                    j += 1 << i;
                }
            }
            long long d = 0;
            while (w > 0 && j >= 0) {
                q = v;
                for (int i = 19; i >= 0; i--) {
                    if (j & (1 << i)) {
                        q = p[q][i];
                    }
                }
                if (a[q] > w) {
                    d += w * c[q];
                    a[q] -= w;
                    w = 0;
                    break;
                } else {
                    w -= a[q];
                    d += a[q] * c[q];
                    a[q] = 0;
                }
                j--;
            }
            cout << ww - w << " " << d << endl;
        }
    }
    return 0;
}