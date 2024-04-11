#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int mod = 1e9 + 7;
int a[maxn], c[2];

using matrix = vector<vector<int>>;

matrix mult(const matrix &a, const matrix &b) {
    int n = (int)a.size();
    matrix c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * 1ll * b[k][j] % mod;
                if (c[i][j] >= mod) c[i][j] -= mod;
            }
        }
    }
    return c;
}

matrix fpow(matrix a, int k) {
    int n = (int)a.size();
    matrix c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) c[i][i] = 1;

    while (k > 0) {
        if (k & 1)
            c = mult(c, a);
        a = mult(a, a);
        k >>= 1;
    }
    return c;
}

int fpow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1)
            res = res * 1ll * a % mod;
        a = a * 1ll * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) c[a[i]]++;

    int m = min(c[0], c[1]);
    matrix mt(m + 1, vector<int>(m + 1, 0));
    int pr = n * (n - 1) / 2, iv = fpow(pr, mod - 2);

    for (int i = 0; i <= m; ++i) {
        int bb = c[0] - i, bw = i;
        int wb = i, ww = c[1] - i;
        mt[i][i] += bb * (bb - 1) / 2 * 1ll * iv % mod; 
        mt[i][i] %= mod;
        mt[i][i] += ww * (ww - 1) / 2 * 1ll * iv % mod;
        mt[i][i] %= mod;
        mt[i][i] += bw * (bw - 1) / 2 * 1ll * iv % mod;
        mt[i][i] %= mod;
        mt[i][i] += wb * (wb - 1) / 2 * 1ll * iv % mod;
        mt[i][i] %= mod;
        mt[i][i] += bb * bw * 1ll * iv % mod;
        mt[i][i] %= mod;
        mt[i][i] += ww * wb * 1ll * iv % mod;
        mt[i][i] %= mod;
        mt[i][i] += bb * wb * 1ll * iv % mod;
        mt[i][i] %= mod;
        mt[i][i] += ww * bw * 1ll * iv % mod;
        mt[i][i] %= mod;
        if (i - 1 >= 0) {
            mt[i - 1][i] += bw * wb * 1ll * iv % mod;
            mt[i - 1][i] %= mod;
        }
        if (i + 1 <= m) {
            mt[i + 1][i] += ww * bb * 1ll * iv % mod;
            mt[i + 1][i] %= mod;
        }
    }

    mt = fpow(mt, k);

    int init = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && i >= c[0])
            ++init;
    }

    printf("%d\n", mt[0][init]);
    return 0;
}