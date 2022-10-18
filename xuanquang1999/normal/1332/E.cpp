#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

struct matrix {
    int n, m;
    vector<vector<int>> a;

    matrix(int n, int m): n(n), m(m) {
        a.assign(n, vector<int>(m, 0));
    }
};

matrix mul(matrix A, matrix B) {
    matrix C(A.n, B.m);
    for(int i = 0; i < A.n; ++i) 
        for(int j = 0; j < B.m; ++j) 
            for(int k = 0; k < A.m; ++k)
                C.a[i][j] = (C.a[i][j] + 1LL * A.a[i][k] * B.a[k][j]) % MOD;
    return C;
}

matrix identity(int n) {
    matrix res(n, n);
    for(int i = 0; i < n; ++i)
        res.a[i][i] = 1;
    return res;
}

matrix power(matrix A, long long n) {
    matrix res = identity(A.n);
    while (n) {
        if (n&1) res = mul(res, A);
        A = mul(A, A);
        n >>= 1;
    }
    return res;
}

int main() {
    int n, m, L, R;
    scanf("%d%d%d%d", &n, &m, &L, &R);

    matrix F(2, 1);
    F.a[0][0] = 1;
    F.a[1][0] = 0;

    int cnt0 = R/2 - (L-1)/2, cnt1 = (R+1)/2 - L/2;
    // printf("%d %d\n", cnt0, cnt1);
    matrix A(2, 2);
    A.a[0][0] = cnt0; A.a[0][1] = cnt1;
    A.a[1][0] = cnt1; A.a[1][1] = cnt0;

    A = power(A, 1LL * n * m);
    F = mul(A, F);

    int ans = F.a[0][0];
    if (n%2 == 1 && m%2 == 1)
        ans = (ans + F.a[1][0]) % MOD;
    printf("%d\n", ans);

    return 0;
}