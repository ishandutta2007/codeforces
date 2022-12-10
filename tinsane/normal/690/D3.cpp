#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;
const int N = 105;
const int MOD = (int)1e6 + 3;

int add(int a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
    return a;
}

int mul(int a, int b)
{
    return (ll)a * b % MOD;
}

struct Matrix
{
    int a[N][N];

    Matrix(int e = 0): a()
    {
        for (int i = 0; i < N; i++)
            a[i][i] = e;
    }

    int *operator[](int p)
    {
        return a[p];
    }

    const int *operator[](int p) const
    {
        return a[p];
    }

    Matrix operator*(const Matrix &b) const
    {
        Matrix c;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                for (int k = 0; k < N; k++)
                    c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
        return c;
    }
};

Matrix bin_pow(Matrix a, int b)
{
    Matrix res(1);
    while (b > 0)
    {
        if (b % 2 == 1)
            res = res * a;
        a = a * a;
        b /= 2;
    }
    return res;
}

int c, w, h;
int pow_h[N];
Matrix mat, vec;

void solve()
{
    scanf("%d%d%d", &c, &w, &h);
    c++; w++;

    pow_h[0] = 1;
    for (int i = 1; i < N; i++)
        pow_h[i] = mul(pow_h[i - 1], h);

    for (int len = 1; len <= w; len++)
        mat[0][len - 1] = pow_h[len - 1];
    for (int i = 1; i < w; i++)
        mat[i][i - 1] = 1;

    mat = bin_pow(mat, c);
    vec[0][0] = 1;
    vec = vec * mat;

    printf("%d\n", vec[0][0]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}