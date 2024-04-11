#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll x;
ll MOD = (ll)(1e9 + 7);
int n, d;
int a[100100], b[100100], c[100100];
int e[100100];
pair<int, int> f[100100];

int rnd()
{
    x = (x * 37LL + 10007LL) % MOD;
    return (int)x;
}
void init()
{
    scanf("%d%d%I64d", &n, &d, &x);
    for (int i = 0; i < n; i++)
    {
        a[i] = i + 1;
        if (i < d)
            b[i] = 1;
    }
    for (int i = 0; i < n; i++)
        swap(a[i], a[rnd() % (i + 1)]);
    for (int i = 0; i < n; i++)
        swap(b[i], b[rnd() % (i + 1)]);
}

void solve1()
{
    int sz = 0;
    for (int i = 0; i < n; i++)
        if (b[i] == 1)
            e[sz++] = i;
    if (d != sz)
        throw;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < d; j++)
        {
            if (e[j] > i)
                break;
            c[i] = max(c[i], a[i - e[j]]);
        }
    }
    return;
}

int main()
{
    init();
    if (((int)3e8 / n) / d > 0)
    {
        solve1();
        for (int i = 0; i < n; i++)
            printf("%d\n", c[i]);
        return 0;
    }

    for (int i = 0; i < (int)1e4; i++)
        for (int j = 0; j <= i; j++)
            if (b[i - j] == 1)
                c[i] = max(c[i], a[j]);
    for (int i = 0; i < n; i++)
        f[i] = make_pair(a[i], i);
    sort(f, f + n);
    reverse(f, f + n);
    for (int i = (int)1e4; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (f[j].second <= i && b[i - f[j].second] == 1)
            {
                c[i] = n - j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", c[i]);
    printf("\n");

    return 0;
}