#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn], c[maxn];

long long comb(int x, int t, long long v = 1ll) {
    for (int i = 1; i <= t; ++i) v *= 1ll * (x - i + 1);
    for (int i = 1; i <= t; ++i) v /= i;
    return v;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int g, d, f; cin >> g >> d >> f;
    int t;
    for (int i = 0; i < g; ++i) cin >> t, ++a[t];
    for (int i = 0; i < d; ++i) cin >> t, ++b[t];
    for (int i = 0; i < f; ++i) cin >> t, ++c[t];
    for (int i = 1; i <= 200000; ++i) a[i] += a[i - 1], b[i] += b[i - 1], c[i] += c[i - 1];
    long long ans = 0;
    for (int t = 1; t <= 100000; ++t) {
        int va = a[t] - a[t - 1], vb = b[t] - b[t - 1], vc = c[t] - c[t - 1];
        int ta = a[t * 2] - a[t], tb = b[t * 2] - b[t], tc = c[t * 2] - c[t];
        for (int i = 0; i <= 1; ++i) {
            for (int j = 0; j <= 2; ++j) {
                for (int k = 0; k <= 3; ++k) ans += comb(va, i) * comb(ta, 1 - i) * comb(vb, j) * comb(tb, 2 - j) * comb(vc, k) * comb(tc, 3 - k);
            }
        }
        ans -= comb(ta, 1) * comb(tb, 2) * comb(tc, 3);
    }
    long long tans = (long long)ans;
    cout << tans << endl;
}