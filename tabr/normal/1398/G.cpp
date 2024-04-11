#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

const double PI = acos(-1);
int base = 1;
vector<complex<double>> roots = {{0, 0}, {1, 0}};
vector<int> rev = {0, 1};

vector<complex<double>> f;

void ensure_base(int nbase) {
    if (nbase <= base) {
        return;
    }
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
        double angle = 2 * PI / (1 << (base + 1));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
            roots[i << 1] = roots[i];
            double angle_i = angle * (2 * i + 1 - (1 << base));
            roots[(i << 1) + 1] = complex<double>(cos(angle_i), sin(angle_i));
        }
        base++;
    }
}

void fft(vector<complex<double>>& a, int n) {
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                complex<double> z = a[i + j + k] * roots[j + k];
                a[i + j + k] = a[i + j] - z;
                a[i + j] = a[i + j] + z;
            }
        }
    }
}

vector<long long> multiply(const vector<long long>& a, const vector<long long>& b) {
    int need = (int)a.size() + (int)b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) {
        nbase++;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int)f.size()) {
        f.resize(sz);
    }
    for (int i = 0; i < sz; i++) {
        int x = (i < (int)a.size() ? a[i] : 0);
        int y = (i < (int)b.size() ? b[i] : 0);
        f[i] = complex<double>(x, y);
    }
    fft(f, sz);
    complex<double> r(0, -0.25 / (sz >> 1));
    for (int i = 0; i <= (sz >> 1); i++) {
        int j = (sz - i) & (sz - 1);
        complex<double> z = (f[j] * f[j] - conj(f[i] * f[i])) * r;
        f[j] = (f[i] * f[i] - conj(f[j] * f[j])) * r;
        f[i] = z;
    }
    for (int i = 0; i < (sz >> 1); i++) {
        complex<double> a0 = (f[i] + f[i + (sz >> 1)]) * complex<double>(0.5, 0);
        complex<double> a1 = (f[i] - f[i + (sz >> 1)]) * complex<double>(0.5, 0) * roots[(sz >> 1) + i];
        f[i] = a0 + a1 * complex<double>(0, 1);
    }
    fft(f, sz >> 1);
    vector<long long> res(need);
    for (int i = 0; i < need; i++) {
        res[i] = llround(i % 2 == 0 ? f[i >> 1].real() : f[i >> 1].imag());
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    vector<ll> b(x + 1), c(x + 1);
    for (int i = 0; i <= n; i++) {
        int a;
        cin >> a;
        b[a] = 1;
        c[x - a] = 1;
    }
    vector<ll> d = multiply(b, c);
    int z = 1000500;
    vector<int> ans(z, -1);
    for (int i = 0; i < x; i++) {
        if (d[i]) {
            ans[2 * (x - i + y)] = 2 * (x - i + y);
        }
    }
    for (int i = 1; i < z; i++) {
        for (int j = i * 2; j < z; j += i) {
            ans[j] = max(ans[j], ans[i]);
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int l;
        cin >> l;
        cout << ans[l] << " ";
    }
    cout << '\n';
    return 0;
}