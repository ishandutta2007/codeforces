#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

const int N = 30, M = N * (N - 1);

struct Matrix {
    double a[M][M];

    Matrix() {
        memset(a, 0, sizeof(a));
    }

    void clear() {
        memset(a, 0, sizeof(a));
    }

    double* operator[] (const int i) {
        return a[i];
    }

    const double* operator[] (const int i) const {
        return a[i];
    }
};

int n, k, m;

Matrix ret;

void mul(const Matrix &a, const Matrix &b) {
    ret.clear();
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < m; ++k) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

double u[M], v[M];

void mult(double u[M], const Matrix &a, double v[M]) {
    for (int i = 0; i < m; ++i) {
        v[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            v[j] += u[i] * a[i][j];
        }
    }
}

int p[N];

int id[N][N];

int main() {
//cout << N << ' ' << M << ' ' << sizeof(ret) << endl;
    scanf("%d%d", &n, &k);
    if (n == 1) {
        printf("%.12f\n", 0.0);
        return 0;
    }
    m = n * (n - 1);
    int mm = n * (n + 1) / 2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            id[i][j] = cnt++;
        }
    }
    for (int i = 0; i < n; ++i) {
        p[i] = i;
    }
    Matrix A;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            reverse(p + i, p + j + 1);
            for (int a = 0; a < n; ++a) {
                for (int b = 0; b < n; ++b) {
                    if (a == b) {
                        continue;
                    }
                    int x = p[a], y = p[b];
                    A[id[x][y]][id[a][b]] += 1.0 / mm;
                }
            }
            reverse(p + i, p + j + 1);
        }
    }
    /*
    Matrix B;
    for (int i = 0; i < m; ++i) {
        B[i][i] = 1;
    }
    int bak = k;
    while (k) {
        if (k & 1) {
            mul(B, A);
            B = ret;
        }
        mul(A, A);
        A = ret;
        k >>= 1;
    }
    */
    for (int i = 0; i < n; ++i) {
        scanf("%d", p + i);
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) {
                continue;
            }
            if (p[i] > p[j]) {
                u[id[i][j]] = 1;
            }
        }
    }
    for (int i = 0; i < k; ++i) {
        mult(u, A, v);
        for (int j = 0; j < m; ++j) {
            u[j] = v[j];
        }
    }
    for (int x = 0; x < n; ++x) {
        for (int y = 0; y < n; ++y) {
            if (x == y) {
                continue;
            }
            //cout << i << ' ' << j << ' ' << x << ' ' << y << ' ' << B[id[i][j]][id[x][y]] << endl;
            if (x < y) {
                ans += v[id[x][y]];
            }
        }
    }
    printf("%.12f\n", ans);
    return 0;
}