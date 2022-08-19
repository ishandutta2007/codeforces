#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const ll MOD = (ll)1e9 + 7;
const int N = (int)1e7 + 10;
int a[N];
int mu[N];
ll pow2[N];

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

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    pow2[0] = 1;
    for (int i = 1; i < N; i++)
        pow2[i] = add(pow2[i - 1], pow2[i - 1]);
    for (int i = 2; i < N; i++)
    {
        mu[i]++;
        for (int j = 2 * i; j < N; j += i)
            mu[j] -= mu[i];
    }
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x]++;
    }
    ll A = 0;
    for (int d = 2; d < N; d++)
    {
        if (mu[d] == 0) continue;
        int c = 0;
        for (int i = d; i < N; i += d)
            c += a[i];
        if (c == 0) continue;
        if (mu[d] == 1)
            A = add(A, mult(n - c, sub(pow2[c], 1)));
        else
            A = sub(A, mult(n - c, sub(pow2[c], 1)));
    }
    printf("%lld\n", A);

    return 0;
}