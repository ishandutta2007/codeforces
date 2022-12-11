#include <cstdio>
#include <algorithm>

using namespace std;

#define long long long

const int N = 1e5 + 2;

int n, p;
long a[N];

int main()
{
    scanf("%d %d", &n, &p);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), a[i] += a[i - 1];
    long res = 0;
    for (int i = 1; i < n; ++i)
        res = max(res, a[i] % p + (a[n] - a[i] + p) % p);
    printf("%lld", res);
    return 0;
}