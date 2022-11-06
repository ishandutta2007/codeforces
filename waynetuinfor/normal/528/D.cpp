#include <bits/stdc++.h>
using namespace std;

const int maxn = 524288;
complex<double> omega[maxn + 1];
const double pi = acos(-1);
const complex<double> I(0, 1);

void prefft() {
    for (int i = 0; i <= maxn; ++i) omega[i] = exp(i * 2 * pi / maxn * I);
}

void fft(vector<complex<double>>& a, int n, bool inv=false) {
    int basic = maxn / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        int h = m >> 1;
        for (int i = 0; i < h; ++i) {
            complex<double> w = omega[inv ? maxn - (i * theta % maxn) : i * theta % maxn];
            for (int j = i; j < n; j += m) {
                int k = j + h;
                complex<double> x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta = (theta * 2) % maxn;
    }
    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    if (inv) for (int i = 0; i < n; ++i) a[i] /= (double)n;
}

void invfft(vector<complex<double>>& a, int n) {
    fft(a, n, true);
}

vector<char> ch = { 'A', 'C', 'T', 'G' };
int ans[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    string s, t; cin >> s >> t;
    reverse(t.begin(), t.end());
    prefft();
    int d = 1; while (d < (n << 1)) d <<= 1;
    for (char c : ch) {
        vector<complex<double>> a(d), b(d), f(d);
        for (int i = 0; i < n; ++i) if (s[i] == c) {
            a[i] = complex<double>(1, 0);
            for (int j = i - 1; i - j <= k && s[j] != c && j >= 0; --j) a[j] = complex<double>(1, 0);
            for (int j = i + 1; j - i <= k && s[j] != c && j < n; ++j)  a[j] = complex<double>(1, 0);
        }
        for (int i = 0; i < m; ++i) if (t[i] == c) b[i] = complex<double>(1, 0);
        fft(a, d); fft(b, d);
        for (int i = 0; i < d; ++i) f[i] = a[i] * b[i];
        invfft(f, d);
        for (int i = 0; i < d; ++i) ans[i] += (int)(round(f[i].real()));
    }    
    int cnt = 0;
    for (int i = 0; i < d; ++i) if (ans[i] == m) ++cnt;
    cout << cnt << endl;
    return 0;
}