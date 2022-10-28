#include <bits/stdc++.h>
using namespace std;

const int N = 200000;

int x[N], y[N], z[N], n;

int solve(int a, int l, int p = -1) {
    int b = upper_bound(x, x + n, x[a] + l) - x - 1;
    if (a == b) {
        b = lower_bound(x, x + n, x[a] - l) - x;
        if (a == b) {
            return a;
        }
    }

    int d = abs(x[a] - x[b]);
    if (b == p && l / 2 >= d) {
        return solve(a, l % (2 * d), p);
    }

    return solve(b, l - d, a);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    iota(y, y + n, 0);
    sort(y, y + n, [&](int a, int b) {
        return x[a] < x[b];
    });

    sort(x, x + n);

    for (int i = 0; i < n; ++i) {
        z[y[i]] = i;
    }

    for (int i = 0; i < m; ++i) {
        int a, l;
        cin >> a >> l;
        cout << y[solve(z[a - 1], l)] + 1 << "\n";
    }
}