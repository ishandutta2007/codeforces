#include <bits/stdc++.h>
using namespace std;

long long u[2], v[2], m;

long long calc(long long h, long long a, long long x, long long y) {
    for (int i = 1; i <= m; ++i) {
        h = (x * h + y) % m;
        if (h == a) {
            return i;
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m;

    for (int i = 0; i < 2; ++i) {
        long long h, a, x, y;
        cin >> h >> a >> x >> y;
        u[i] = h == a ? 0 : calc(h, a, x, y);
        v[i] = calc(a, a, x, y);
    }

    if (u[0] > -1 && u[1] > -1) {
        for (int i = 0; i < m; ++i) {
            if (u[0] >= u[1]) {
                bool ok = v[1] != -1 && (u[0] - u[1]) % v[1] == 0;
                ok |= u[0] == u[1];
                if (ok) {
                    cout << u[0] << "\n";
                    exit(0);
                }
            }

            if (v[0] > -1) {
                u[0] += v[0];
            } else {
                break;
            }
        }
    }

    cout << -1 << "\n";
}