#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r

using namespace std;

LL n, k, l, mod;

struct mat {
    LL a[3][3];
    mat () {
        memset (a, 0, sizeof a);
    }
};

mat mul (mat A, mat B) {
    mat C;
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 2; k++) {
                (C.a[i][j] += A.a[i][k] * B.a[k][j] % mod) %= mod;
            }
        }
    }
    return C;
}

mat matpow (mat A, LL k) {
    mat C;
    C.a[1][1] = C.a[2][2] = 1;
    while (k) {
        if (k & 1) C = mul (C, A);
        A = mul (A, A);
        k >>= 1;
    }
    return C;
}

LL pm (LL x, LL y) {
    LL r = 1;
    while (y) {
        if (y & 1) (r *= x) %= mod;
        (x *= x) %= mod;
        y >>= 1;
    }
    return r;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> k >> l >> mod;
//    cout << n << ' ' << k << ' '<< l << ' ' << mod <<endl;
    mat A;
    A.a[1][1] = A.a[1][2] = A.a[2][1] = 1;
    A = matpow(A, n + 1);
//    cout << 'x' << endl;
    LL all = pm (2, n);
    LL c1 = A.a[1][1];
    LL c2 = (all - c1 + mod) % mod;
//    cout << c1 << ' ' << c2 << ' ' << all << endl;
//    for (int i = 1; i <= 2; i++) {
//        for (int j = 1; j <= 2; j++) {
//            cout << A.a[i][j] << ' ';
//        } cout << endl;
//    }
    LL res = 1 % mod;
    if (l < 63 && k >= (1LL << l)) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < l; i++) {
//        cout << i << endl;
        if (i >= 63 || (((1LL << i) & k) == 0)) (res *= c1) %= mod;
        else (res *= c2) %= mod;
    }
    cout << res << endl;
}