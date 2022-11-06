#include <bits/stdc++.h>
using namespace std;
using cplx = complex<double>;

const int maxn = 262144, mod = 1009;
const double eps = 1e-9;
const double pi = acos(-1);
const cplx I = cplx(0, 1);

int c[maxn];
cplx omega[maxn + 1];

void prefft() {
    for (int i = 0; i <= maxn; ++i) omega[i] = exp(2 * i * pi / maxn * I);
}

void bin(vector<cplx> &v, int n) {
    int z = 0;
    for (; (1 << z) < n; ++z); --z;
    for (int i = 0; i < n; ++i) {
        int p = 0;
        for (int j = 0; (1 << j) < n; ++j) p ^= (((i >> j) & 1) << (z - j));
        if (i < p) swap(v[i], v[p]);
    }
}

void fft(vector<cplx> &v, int n) {
    bin(v, n);
    for (int s = 2; s <= n; s <<= 1) {
        int z = s >> 1;
        for (int i = 0; i < n; i += s) {
            for (int k = 0; k < z; ++k) {
                cplx x = omega[maxn / s * k] * v[i + z + k];
                v[i + z + k] = v[i + k] - x;
                v[i + k] += x;
            }
        }
    }
}

void ifft(vector<cplx> &v, int n) {
    fft(v, n);
    reverse(v.begin() + 1, v.end());
    for (int i = 0; i < n; ++i) v[i] /= n;
}

vector<int> poly[maxn];

int polymul(int a, int b) {
    // printf("( "); for (int i = 0; i < poly[a].size(); ++i) printf("%d ", poly[a][i]); printf(") x ");
    // printf("( "); for (int i = 0; i < poly[b].size(); ++i) printf("%d ", poly[b][i]); printf(") = ");
    int d = 1;
    while (d < max(poly[a].size(), poly[b].size())) d <<= 1; d <<= 1;
    vector<cplx> va(d, cplx(0, 0)), vb(d, cplx(0, 0));
    for (int i = 0; i < poly[a].size(); ++i) va[i] = cplx(1.0 * poly[a][i], 0);
    for (int i = 0; i < poly[b].size(); ++i) vb[i] = cplx(1.0 * poly[b][i], 0);
    fft(va, d), fft(vb, d);
    for (int i = 0; i < d; ++i) va[i] *= vb[i];
    ifft(va, d);
    poly[a].clear();
    // for (int i = 0; i < d; ++i) printf("%.2lf ", va[i].real()); puts("");
    for (int i = 0; i < d; ++i) poly[a].push_back((long long)(va[i].real() + 0.5) % mod);
    int p = poly[a].size() - 1;
    while (p >= 0 && poly[a][p] == 0) --p;
    poly[a].resize(p + 1);
    poly[a].shrink_to_fit();
    // printf("( "); for (int i = 0; i < poly[a].size(); ++i) printf("%d ", poly[a][i]); puts(")");
    return p + 1;
}

int main() {
    prefft();
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; ++i) {
        int x; scanf("%d", &x);
        c[x]++;
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= c[i]; ++j) poly[i].push_back(1);
        pq.emplace(poly[i].size(), i);
    }    
    while (pq.size() > 1) {
        int la, a; tie(la, a) = pq.top(); pq.pop();
        int lb, b; tie(lb, b) = pq.top(); pq.pop();
        // printf("a = %d, b = %d\n", a, b);
        pq.emplace(polymul(a, b), a);
    }
    int ans = pq.top().second;
    // printf("ans = %d\n", ans);
    if (poly[ans].size() <= k) printf("0\n");
    else printf("%d\n", poly[ans][k]);
    return 0;
}