#include <bits/stdc++.h>
using namespace std;

struct cplx {
    double re, im;
    cplx(): re(0), im(0) {}
    cplx(double r, double i): re(r), im(i) {}
    cplx operator+(const cplx &rhs) const { return cplx(re + rhs.re, im + rhs.im); }
    cplx operator-(const cplx &rhs) const { return cplx(re - rhs.re, im - rhs.im); }
    cplx operator*(const cplx &rhs) const { return cplx(re * rhs.re - im * rhs.im, re * rhs.im + im * rhs.re); }
    cplx conj() const { return cplx(re, -im); }
}; 

const int maxn = 262144;
const double pi = acos(-1);
cplx omega[maxn + 1];

void prefft() {
    for (int i = 0; i <= maxn; ++i)
        omega[i] = cplx(cos(2 * pi * i / maxn), sin(2 * pi * i / maxn));
}

void bitrev(vector<cplx> &v, int n) {
    int z = __builtin_ctz(n) - 1;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        for (int j = 0; (1 << j) < n; ++j) x ^= (((i >> j & 1)) << (z - j));
        if (x > i) swap(v[x], v[i]);
    }
}

void fft(vector<cplx> &v, int n) {
    bitrev(v, n);
    for (int s = 2; s <= n; s <<= 1) {
        int z = s >> 1;
        for (int i = 0; i < n; i += s) {
            for (int k = 0; k < z; ++k) {
                cplx x = v[i + z + k] * omega[maxn / s * k];
                v[i + z + k] = v[i + k] - x;
                v[i + k] = v[i + k] + x;
            }
        }
    }
}

void ifft(vector<cplx> &v, int n) {
    fft(v, n);
    reverse(v.begin() + 1, v.end());
    for (int i = 0; i < n; ++i) v[i] = v[i] * cplx(1. / n, 0);
}

vector<int> conv(const vector<int> &a, const vector<int> &b) {
    int sz = 1; 
    while (sz < a.size() + b.size() - 1) sz <<= 1;
    vector<cplx> v(sz);
    for (int i = 0; i < sz; ++i) {
        double re = i < a.size() ? a[i] : 0;
        double im = i < b.size() ? b[i] : 0;
        v[i] = cplx(re, im);
    }
    fft(v, sz);
    for (int i = 0; i <= sz / 2; ++i) {
        int j = (sz - i) & (sz - 1);
        cplx x = (v[i] + v[j].conj()) * (v[i] - v[j].conj()) * cplx(0, -0.25);
        if (j != i) v[j] = (v[j] + v[i].conj()) * (v[j] - v[i].conj()) * cplx(0, -0.25);
        v[i] = x;
    }
    ifft(v, sz);
    vector<int> c(sz);
    for (int i = 0; i < sz; ++i) c[i] = round(v[i].re);
    while (c.size() && c.back() == 0) c.pop_back();
    return c;
}

char s[maxn], t[maxn];

struct djset {
    int fa[6], mrg;
    void init() {
        mrg = 0;
        for (int i = 0; i < 6; ++i)
            fa[i] = i;
    }
    int find(int x) {
        if (x == fa[x]) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        if ((x = find(x)) == (y = find(y))) return;
        fa[x] = y;
        ++mrg;
    }
} djs[maxn];

int main() {
    prefft();
    scanf("%s", s);
    scanf("%s", t);
    int n = strlen(s), m = strlen(t);
    for (int i = 0; i < maxn; ++i) djs[i].init();
    for (int i = 0; i < 6; ++i) for (int j = 0; j < 6; ++j) {
        vector<int> a(n), b(m);
        for (int k = 0; k < n; ++k) {
            if (s[k] - 'a' == i) a[k] = 1;
            else a[k] = 0;
        }
        for (int k = 0; k < m; ++k) {
            if (t[m - 1 - k] - 'a' == j) b[k] = 1;
            else b[k] = 0;
        }
        vector<int> c = conv(a, b);
        for (int k = 0; k < c.size(); ++k) {
            if (c[k] > 0) djs[k].merge(i, j);
        }
    }
    for (int i = m - 1; i < n; ++i) printf("%d ", djs[i].mrg);
    puts("");
    return 0;
}