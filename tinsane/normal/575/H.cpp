#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <cassert>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif

typedef long long ll;

const int N = 2e6 + 10;
const int P = (int)1e9 + 7;

int sum(int a, int b)
{
    a += b;
    if (a >= P)
        return a - P;
    return a;
}

int mul(int a, int b)
{
    return (ll)a * b % P;
}

int bpow(int x, int p)
{
    int res = 1;
    for(; p > 0; p /= 2)
    {
        if (p % 2 == 1)
            res = mul(res, x);
        x = mul(x, x);
    }
    return res;
}

int n;
int fact[N], rfact[N];

int cnk(int nn, int k)
{
    return mul(fact[nn], mul(rfact[k], rfact[nn - k]));
}

void solve()
{
    fact[0] = 1;
    for(int i = 1; i < N; ++i)
        fact[i] = mul(fact[i - 1], i);
    for(int i = 0; i < N; ++i)
        rfact[i] = bpow(fact[i], P - 2);
    scanf("%d", &n);
    int res = 0;
    for(int i = 0; i <= n; ++i)
        res = sum(res, cnk(n + i + 1, i + 1));
    printf("%d", res);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);

    return 0;
}