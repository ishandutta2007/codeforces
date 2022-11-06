#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn], b[maxn], a, n, m, s;
bool v[maxn];

bool check(int k) {
    int na = a;
    for (int i = 0; i < k; ++i) {
        if (b[i] >= p[k - i - 1]) continue;
        int diff = p[k - i - 1] - b[i];
        if (na < diff) return false;
        na -= diff;
    }
    return true;
}

void solve(int r) {
    int na = a;
    for (int i = 0; i < r; ++i) {
        if (b[i] < p[r - i - 1]) {
            na -= p[r - i - 1] - b[i];
            p[r - i - 1] = b[i];
        }
    }
    for (int i = 0; i < r; ++i) {
        int t = min(na, p[r - i - 1]);
        na -= t; p[r - i - 1] -= t;
        s += p[r - i - 1];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> a;
    for (int i = 0; i < n; ++i) cin >> b[i];
    for (int j = 0; j < m; ++j) cin >> p[j];
    sort(b, b + n); reverse(b, b + n); sort(p, p + m);
    int d = 131072, r = 0; while (d >>= 1) {
        if (r + d <= min(n, m)) if (check(r + d)) r += d;
    }
    solve(r);
    cout << r << ' ' << s << endl;
    return 0;
}