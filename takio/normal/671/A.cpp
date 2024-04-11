#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 500100;
int x[N], y[N], B[N], C[N];
int a, b, c, d, e, f;
int n, k;

LL sqr (LL x) { return x * x; }

bool cmp1 (int i, int j) {
    return
    sqrt (sqr (x[i] - a) + sqr (y[i] - b)) - sqrt (sqr (x[i] - e) + sqr (y[i] - f)) <
    sqrt (sqr (x[j] - a) + sqr (y[j] - b)) - sqrt (sqr (x[j] - e) + sqr (y[j] - f));
}
bool cmp2 (int i, int j) {
    return
    sqrt (sqr (x[i] - c) + sqr (y[i] - d)) - sqrt (sqr (x[i] - e) + sqr (y[i] - f)) <
    sqrt (sqr (x[j] - c) + sqr (y[j] - d)) - sqrt (sqr (x[j] - e) + sqr (y[j] - f));
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >>a >> b >> c >> d>> e >> f;
    int n;
    cin >> n;
//    cout << n << endl;
    long double res = 0.0;
    for (int i = 1; i <= n; i++) {
        scanf ("%d%d", &x[i], &y[i]);
        res += sqrt (sqr (x[i] - e) + sqr (y[i] - f));
        B[i] = i;
        C[i] = i;
    }
    if (n == 1) {
//        res = 0.0;
        res += min (sqrt (sqr (x[1] - a) + sqr (y[1] - b)), sqrt (sqr (x[1] - c) + sqr (y[1] - d)));
    } else {
        res *= 2;
        long double res2 = res;
        sort (B + 1, B + 1 + n, cmp1);
        sort (C + 1, C + 1 + n, cmp2);
        res2 += min (sqrt (sqr (x[B[1]] - a) + sqr (y[B[1]] - b)) - sqrt (sqr (x[B[1]] - e) + sqr (y[B[1]] - f)), sqrt (sqr (x[C[1]] - c) + sqr (y[C[1]] - d)) - sqrt (sqr (x[C[1]] - e) + sqr (y[C[1]] - f)));
//        cout << B[1] << ' ' << C[1] << endl;
//        cout << B[2] << ' ' << C[2] << endl;
        if (B[1] != C[1]) {
            res += sqrt (sqr (x[B[1]] - a) + sqr (y[B[1]] - b)) - sqrt (sqr (x[B[1]] - e) + sqr (y[B[1]] - f));
            res += sqrt (sqr (x[C[1]] - c) + sqr (y[C[1]] - d)) - sqrt (sqr (x[C[1]] - e) + sqr (y[C[1]] - f));
        } else {
            long double tmp1 = 0.0, tmp2 = 0.0;
            tmp1 += sqrt (sqr (x[B[1]] - a) + sqr (y[B[1]] - b)) - sqrt (sqr (x[B[1]] - e) + sqr (y[B[1]] - f));
            tmp1 += sqrt (sqr (x[C[2]] - c) + sqr (y[C[2]] - d)) - sqrt (sqr (x[C[2]] - e) + sqr (y[C[2]] - f));
            tmp2 += sqrt (sqr (x[B[2]] - a) + sqr (y[B[2]] - b)) - sqrt (sqr (x[B[2]] - e) + sqr (y[B[2]] - f));
            tmp2 += sqrt (sqr (x[C[1]] - c) + sqr (y[C[1]] - d)) - sqrt (sqr (x[C[1]] - e) + sqr (y[C[1]] - f));
            res += min (tmp1, tmp2);
        }
        res = min (res2, res);
    }
    printf ("%.10f", (double)res);
}