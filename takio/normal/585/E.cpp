#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 500100, mod = 1e9 + 7, M = 10000001;
int f[N], p[M], tot, c[M], mu[M], a[N], b[N][20], bn[N];
//int t[M], tn;
bool is[M];

int cal (int x) {
    return f[x] - 1;
}

void add (int &x, int y) {
    if (y < 0) y += mod;
    x += y;
    if (x >= mod) x -= mod;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = f[i - 1] * 2 % mod;
    mu[1] = 1;
    for (int i = 2; i < M; i++) {
        if (!is[i]) {
            p[tot++] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < tot && i * p[j] < M; j++) {
            is[i * p[j]] = 1;
            if (i % p[j] == 0) {
                mu[i * p[j]] = 0;
                break;
            }
            mu[i * p[j]] = -mu[i];
        }
    }
//    for (int i = 1; i * i < M; i++) if (mu[i]) t[++tn] = i;
//    for (int i = 1; i <= tn; i++) cout << t[i] <<' ';
//    return 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a[i]);
        int tmp = a[i];
        bn[i] = 0;
        for (int j = 0; p[j] * p[j] <= tmp; j++) if (tmp % p[j] == 0) {
            while (tmp % p[j] == 0) tmp /= p[j];
            b[i][bn[i]++] = p[j];
//            if (mu[j] && j != 1) {
////                cout << i << ' ' << j <<endl;
//                c[j]++;
//            }
//            int tmp = a[i] / j;
//            if (tmp != j && mu[tmp]) {
////                cout << i << ' ' << tmp << endl;
//                c[tmp]++;
//            }
        }
        if (tmp != 1) b[i][bn[i]++] = tmp;
        for (int j = 1; j < (1 << bn[i]); j++) {
            int tmp = 1;
            for (int k = 0; k < bn[i]; k++) if (j & (1 << k)) {
                tmp *= b[i][k];
            }
//            cout << i << ' ' << tmp << endl;
            c[tmp]++;
        }
//        if (a[i] != 1) c[a[i]]++;
//        a[i] = tmp;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
//        res = 0;
        add (res, cal (n - 1));
//        int tmp = a[i];
//        bn = 0;
//        for (int j = 0; p[j] * p[j] <= tmp; j++) if (tmp % p[j] == 0) {
//            while (tmp % p[j] == 0) tmp /= p[j];
//            b[bn++] = p[j];
////            while (a[i] % t[j] == 0) a[i] /= t[j];
////            cout << mu[t[j]] << ' ' << cal (c[t[j]] - 1) << endl;
////            if (mu[j] && j != 1) {
////                add (res, mu[j] * cal (c[j] - 1));
//////                cout << i << ' ' << c[j] - 1 << endl;
////            }
////            int tmp = a[i] / j;
////            if (tmp != j && mu[tmp]) {
////                add (res, mu[tmp] * cal (c[tmp] - 1));
//////                cout << i << ' ' << c[tmp] - 1 << endl;
////            }
//        }
//        if (tmp != 1) b[bn++] = tmp;
        for (int j = 1; j < (1 << bn[i]); j++) {
            int tmp = 1;
            for (int k = 0; k < bn[i]; k++) if (j & (1 << k)) {
                tmp *= b[i][k];
            }
//            cout << i << ' ' << tmp << endl;
            add (res, mu[tmp] * cal (c[tmp] - 1));
        }
//        if (a[i] != 1) add (res, mu[a[i]] * cal (c[a[i]] - 1));
//        cout << i << ' ' << res << endl;
    }
//    cout << res << endl;
    add (res, -1LL * n * cal (n - 1) % mod);
//    cout << res << endl;
    for (int i = 2; i < M; i++) if (c[i]) {
//        cout << i << ' ' << c[i] << ' ' << - (1LL * c[i] * cal(c[i] - 1) + 1LL * (n - c[i]) * cal (c[i])) << endl;
//        cout << i << ' ' <<c[i] <<endl;
        add (res, -mu[i] * (1LL * c[i] * cal(c[i] - 1) + 1LL * (n - c[i]) * cal (c[i])) % mod);
    }
    cout << res << endl;
}