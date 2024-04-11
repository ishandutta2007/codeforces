#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

const int N = 200100;
ll a[N];
ll b[N];
ll c[N];
ll x;
int k;
int n;

int main()
{
    scanf("%d%d%lld", &n, &k, &x);
    ll y = 1;
    for (int i = 0; i < k; i++)
        y *= x;
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    b[0] = 0;
    for (int i = 0; i < n; i++)
        b[i + 1] = b[i] | a[i];
    c[n] = 0;
    for (int i = n - 1; i >= 0; i--)
        c[i] = c[i + 1] | a[i];
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, b[i] | c[i + 1] | (a[i] * y));
    }
    printf("%lld\n", ans);

    return 0;
}