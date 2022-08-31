#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
    if (p == 0) return 1;
    if (p == 2 || (p & 1)) return mult(x, bin_pow(x, p - 1));
    return bin_pow(bin_pow(x, 2), p / 2);
}
ll rev(ll x)
{
    return bin_pow(x, MOD - 2);
}

const int N = 300300;
ll f[N], rf[N];

ll getC(int n, int k)
{
    if (k < 0 || k > n) return 0;
    return mult(f[n], mult(rf[k], rf[n - k]));
}

ll ways(ll n, ll b, ll k)
{
    if (b * k > n) return 0;
    return getC(n - b * k + k - 1, k - 1);
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = mult(f[i - 1], i);
    rf[N - 1] = rev(f[N - 1]);
    for (int i = N - 1; i > 0; i--)
        rf[i - 1] = mult(rf[i], i);

    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if (b == 0)
    {
        printf("1\n");
        return 0;
    }
    if (a == 0)
    {
        printf("%d\n", (b > c ? 1 : 0));
        return 0;
    }

    ll p = 0, q = 0;
    for (int l = 1; l <= a + b; l++)
    {
        q = add(q, mult(ways(a, 1, (l + 1) / 2), ways(b, 1, l / 2)));
        q = add(q, mult(ways(a, 1, l / 2), ways(b, 1, (l + 1) / 2)));

        p = add(p, mult(ways(a, 1, (l + 1) / 2), ways(b, c + 1, l / 2)));
        p = add(p, mult(ways(a, 1, l / 2), ways(b, c + 1, (l + 1) / 2)));
    }
    printf("%lld\n", mult(p, rev(q)));

    return 0;
}