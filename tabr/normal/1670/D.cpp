#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

namespace FFT {
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

template <typename T>
vector<long long> multiply(const vector<T>& a, const vector<T>& b) {
    int need = (int) a.size() + (int) b.size() - 1;
    int nbase = 1;
    while ((1 << nbase) < need) {
        nbase++;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    if (sz > (int) f.size()) {
        f.resize(sz);
    }
    for (int i = 0; i < sz; i++) {
        T x = (i < (int) a.size() ? a[i] : 0);
        T y = (i < (int) b.size() ? b[i] : 0);
        f[i] = complex<double>((double) x, (double) y);
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
}  // namespace FFT

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        long long n;
        cin >> n;
        long long low = 0;
        long long high = 50000;
        while (high - low > 1) {
            long long mid = (high + low) >> 1;
            long long cnt = 0;
            vector<long long> a = {(mid + 2) / 3, (mid + 1) / 3, mid / 3};
            for (int i = 0; i < 3; i++) {
                cnt += a[i] * a[(i + 2) % 3];
            }
            // vector<int> c0(a[0], 1);
            // vector<int> c1(a[1], 1);
            // auto c = FFT::multiply(c0, c1);
            // sort(c.rbegin(), c.rend());
            // for (int i = 0; i < a[2]; i++) {
            //     cnt += c[i];
            // }
            if (cnt * 2 >= n) {
                high = mid;
            } else {
                low = mid;
            }
        }
        cout << high << '\n';
    }
    return 0;
}