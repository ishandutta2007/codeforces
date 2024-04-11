#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef long long ll;

const ll INF = (ll)1e9 + 100;
const int N = 500300;
int n;
ll a[N];
ll ans;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    ll m = INF;
    for (int i = 0; i < n; i++)
        m = min(m, a[i]);
    ans = m * n;
    for (int i = 0; i < n; i++)
        a[i] -= m;
    for (int i = 0; i < n; i++)
        a[n + i] = a[i];
    ll p = 0;
    int lst = -1;
    for (int i = 0; i < 2 * n; i++)
    {
        if (a[i] != 0) continue;
        if (lst != -1)
            p = max(p, (ll)i - lst - 1);
        lst = i;
    }
    printf("%lld\n", ans + p);

    return 0;
}