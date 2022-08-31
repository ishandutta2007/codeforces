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


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    ll n, k;
    scanf("%lld%lld", &n, &k);
    if (k > (ll)1e8)
    {
        printf("-1\n");
        return 0;
    }
    ll b = n / (k * (k + 1) / 2);
    if (b == 0)
    {
        printf("-1\n");
        return 0;
    }
    ll r = 1;
    for (ll x = 1; x * x <= n; x++)
    {
        if (n % x != 0) continue;
        if (x <= b && x > r) r = x;
        if (n / x <= b && n / x > r) r = n / x;
    }
    for (int i = 1; i < k; i++)
        printf("%lld ", r * i);
    n -= r * k * (k - 1) / 2;
    printf("%lld\n", n);

    return 0;
}