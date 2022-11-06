#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 1;
double p[maxn];

struct matrix {
    double dat[maxn * maxn];
    int n, m;
    matrix(int _n, int _m): n(_n), m(_m) { memset(dat, 0, sizeof(dat)); }
    double& operator()(const int &i, const int &j) { return dat[i * m + j]; }
};

matrix matmul(matrix &a, matrix &b) {
    matrix ret(a.n, b.m);
    for (int i = 0; i < a.n; ++i) {
        for (int k = 0; k < b.n; ++k) {
            for (int j = 0; j < b.m; ++j) ret(i, j) += a(i, k) * b(k, j);
        }
    }
    return ret;
}

matrix fpow(matrix a, int n) {
    matrix ret(a.n, a.n);
    for (int i = 0; i < a.n; ++i) ret(i, i) = 1.0;
    for (; n; n >>= 1) {
        if (n & 1) ret = matmul(ret, a);
        a = matmul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    for (int i = 0; i <= x; ++i) cin >> p[i];
    x *= 2;
    matrix tr(x + 1, x + 1);
    for (int i = 0; i <= x; ++i) {
        for (int j = 0; j <= x; ++j) {
            if ((j ^ i) >= 0 && (j ^ i) <= x) tr(i, j ^ i) = p[j];
        }
    }
    tr = fpow(tr, n);
    double s = 0.0;
    cout << fixed << setprecision(20) << 1.0 - tr(0, 0) << endl;
    return 0;
}