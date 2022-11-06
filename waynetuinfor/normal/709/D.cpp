#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int cnt[maxn];

int check(int k) {
    if (k == 0) return 1;
    long long d = 1, ans = maxn; while (d < maxn) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if ((ans - d) * (ans - d - 1) >= 2 * k) ans -= d;
    if (ans * (ans - 1) != 2 * k) return -1;
    return ans;
}

int main() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    int aa = check(a), dd = check(d);
    if (aa == -1 || dd == -1) return cout << "Impossible" << endl, 0;
    bool safe = false;
    if (aa == 1 || dd == 1) {
        if (b + c == 0) safe = true;
    }
    if (!safe && (b + c) != aa * dd) return cout << "Impossible" << endl, 0;
    if (safe) {
        if (aa == 1) aa = 0;
        if (dd == 1) dd = 0;
    }
    // cout << aa << ' ' << dd << endl;
    if (aa == 0) {
        if (dd == 0) dd = 1;
        for (int i = 0; i < dd; ++i) cout << 1;
        return 0;
    }
    if (dd == 0) {
        if (aa == 0) aa = 1;
        for (int i = 0; i < aa; ++i) cout << 0;
        return 0;
    }
    int f = dd - (b + aa - 1) / aa;
    for (int i = 0; i < f; ++i) cout << 1;
    int m = b % aa;
    for (int i = 0; i < aa; ++i) {
        if (m && i == m) cout << 1;
        cout << 0;
    }
    f = b / aa;
    for (int i = 0; i < f; ++i) cout << 1;
    return 0;
}