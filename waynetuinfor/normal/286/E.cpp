#include <bits/stdc++.h>
using namespace std;

const int maxn = 2097152;
const double pi = acos(-1);
using cplx = complex<double>;
const cplx I(0, 1);
cplx omega[maxn + 1];
int a[maxn], cnt[maxn];

void prefft() {
    for (int i = 0; i <= maxn; ++i) omega[i] = exp(2 * pi * i / maxn * I);
}

void bin(vector<cplx> &a, int n) {
    vector<cplx> tmp(n);
    int lg = 0;
    while ((1 << lg) < n) ++lg; --lg;
    for (int i = 0; i < n; ++i) {
        int to = 0;
        for (int j = 0; (1 << j) < n; ++j) to |= (((i >> j) & 1) << (lg - j));
        tmp[to] = a[i];
    }
    for (int i = 0; i < n; ++i) a[i] = tmp[i];
}

void fft(vector<cplx> &a, int n) {
    bin(a, n);
    for (int step = 2; step <= n; step <<= 1) {
        int to = step >> 1;
        for (int i = 0; i < n; i += step) {
            for (int k = 0; k < to; ++k) {
                cplx right = omega[maxn / step * k] * a[i + to + k];
                a[i + to + k] = a[i + k] - right;
                a[i + k] += right;
            }
        }
    }
}

void ifft(vector<cplx> &a, int n) {
    fft(a, n);
    reverse(a.begin() + 1, a.end());
    for (int i = 0; i < n; ++i) a[i] /= n;
}

int main() {
    prefft();
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i]];
    }
    ++m;
    int d = 1; while (d < m) d <<= 1; d <<= 1;
    // cout << "d = " << d << endl;
    vector<cplx> poly(d, 0);
    for (int i = 0; i < m; ++i) if (cnt[i] > 0) poly[i] = cplx(1, 0);
    fft(poly, d);
    for (int i = 0; i < d; ++i) poly[i] *= poly[i];
    ifft(poly, d);
    for (int i = 1; i < m; ++i) {
        int c = round(poly[i].real());
        if (c <= 0) continue;
        // cout << "i = " << i << endl;
        if (cnt[i] == 0) return cout << "NO" << endl, 0;
        cnt[i] = 0;
    } 
    vector<int> ans;
    for (int i = 1; i < m; ++i) if (cnt[i]) ans.push_back(i);
    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}