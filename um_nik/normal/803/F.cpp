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

const int N = 100100;
ll a[N];
ll mu[N];

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    for (int i = 1; i < N; i++)
        a[i] = 1;

    int n;
    scanf("%d", &n);
    while(n--)
    {
        int x;
        scanf("%d", &x);
        a[x] = add(a[x], a[x]);
    }
    for (int x = 1; x < N; x++)
        for (int y = 2 * x; y < N; y += x)
            a[x] = mult(a[x], a[y]);

    mu[1] = 1;
    for (int x = 1; x < N; x++)
        for (int y = 2 * x; y < N; y += x)
            mu[y] = sub(mu[y], mu[x]);

    ll ans = 0;
    for (int i = 1; i < N; i++)
        ans = add(ans, mult(mu[i], sub(a[i], 1)));
    printf("%lld\n", ans);

    return 0;
}