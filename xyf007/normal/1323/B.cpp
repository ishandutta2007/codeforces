#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
int n, m, k, a[40001], b[40001], v1[40001], vv1[40001], tot1, v2[40001], vv2[40001], tot2;
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &b[i]);
    }
    int tmp = 0;
    for (int i = 1; i <= m; i++)
    {
        if (b[i])
        {
            tmp++;
        }
        else
        {
            v1[++tot1] = tmp;
            tmp = 0;
        }
    }
    v1[++tot1] = tmp;
    tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i])
        {
            tmp++;
        }
        else
        {
            v2[++tot2] = tmp;
            tmp = 0;
        }
    }
    v2[++tot2] = tmp;
    sort(v1 + 1, v1 + tot1 + 1);
    sort(v2 + 1, v2 + tot2 + 1);
    for (int i = 1; i <= tot1; i++)
    {
        vv1[i] = vv1[i - 1] + v1[i];
    }
    for (int i = 1; i <= tot2; i++)
    {
        vv2[i] = vv2[i - 1] + v2[i];
    }
    long long ans = 0;
    for (int i = 1; i <= (int)sqrt(k); i++)
    {
        if (!(k % i))
        {
            int pos1 = lower_bound(v1 + 1, v1 + tot1 + 1, i) - v1, pos2 = lower_bound(v2 + 1, v2 + tot2 + 1, k / i) - v2;
            ans += 1LL * (vv1[tot1] - vv1[pos1 - 1] - (i - 1) * (tot1 - pos1 + 1)) * (vv2[tot2] - vv2[pos2 - 1] - (k / i - 1) * (tot2 - pos2 + 1));
            if (i != k / i)
            {
                pos1 = lower_bound(v1 + 1, v1 + tot1 + 1, k / i) - v1;
                pos2 = lower_bound(v2 + 1, v2 + tot2 + 1, i) - v2;
                ans += 1LL * (vv1[tot1] - vv1[pos1 - 1] - (k / i - 1) * (tot1 - pos1 + 1)) * (vv2[tot2] - vv2[pos2 - 1] - (i - 1) * (tot2 - pos2 + 1));
            }
        }
    }
    printf("%lld", ans);
    return 0;
}