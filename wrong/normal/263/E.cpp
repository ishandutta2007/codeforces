#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long lint;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }

const int BIAS = 1500;
int n, m, k, a[3050][3050], X[3050][3050], Y[3050][3050];
lint S[3050][3050];

int main()
{
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &a[i + BIAS][j + BIAS]);
            X[i + BIAS][j + BIAS - k + 1] += a[i + BIAS][j + BIAS];
            X[i + BIAS][j + BIAS - k + 2] += a[i + BIAS][j + BIAS];
            X[i + BIAS][j + BIAS + 1    ] -= a[i + BIAS][j + BIAS] * 2;
            X[i + BIAS][j + BIAS + 2    ] += a[i + BIAS][j + BIAS] * 2;
            X[i + BIAS][j + BIAS + 2 + k] -= a[i + BIAS][j + BIAS];
            X[i + BIAS][j + BIAS + 1 + k] -= a[i + BIAS][j + BIAS];

            Y[i + BIAS - k    ][j + BIAS + 1] -= a[i + BIAS][j + BIAS];
            Y[i + BIAS - k + 1][j + BIAS + 1] -= a[i + BIAS][j + BIAS];
            Y[i + BIAS        ][j + BIAS + 1] += a[i + BIAS][j + BIAS] * 2;
            Y[i + BIAS + 1    ][j + BIAS + 1] -= a[i + BIAS][j + BIAS] * 2;
            Y[i + BIAS + 1 + k][j + BIAS + 1] += a[i + BIAS][j + BIAS];
            Y[i + BIAS     + k][j + BIAS + 1] += a[i + BIAS][j + BIAS];
        }
    }

    for (int i = 0; i < 3050; ++i) {
        for (int j = 1; j < 3050; ++j) {
            X[i][j] += X[i][j - 1];
            S[i][j] += X[i][j];
        }
    }
    for (int i = 1; i < 3050; ++i) {
        for (int j = 0; j < 3050; ++j) {
            Y[i][j] += Y[i - 1][j];
            S[i][j] += Y[i][j];
        }
    }
    for (int i = 3048; i >= 0; --i) {
        for (int j = 1; j < 3050; ++j) {
            S[i][j] += S[i + 1][j - 1];
        }
    }
    for (int i = 1; i < 3050; ++i) {
        for (int j = 1; j < 3050; ++j) {
            S[i][j] += S[i - 1][j - 1];
        }
    }

    lint maxv = -1;
    int a, b;

    for (int i = k - 1; i <= n - k; ++i) {
        for (int j = k - 1; j <= m - k; ++j) {
            if (S[i + BIAS][j + BIAS] > maxv) {
                maxv = S[i + BIAS][j + BIAS];
                a = i + 1;
                b = j + 1;
            }
        }
    }

    printf("%d %d\n", a, b);

    return 0;
}