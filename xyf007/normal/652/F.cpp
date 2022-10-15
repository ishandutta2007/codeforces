#include <bits/stdc++.h>
using namespace std;
int n, m, cnt, p[300001], rk[300001], dir[300001], ans[300001];
long long t;
bool cmp(int a, int b)
{
    return p[a] < p[b];
}
int main()
{
    scanf("%d%d%lld", &n, &m, &t);
    t %= 1LL * n * m;
    for (int i = 1; i <= n; i++)
    {
        char op[10];
        scanf("%d%s", &p[i], op);
        --p[i];
        dir[i] = op[0] == 'L' ? -1 : 1;
        rk[i] = i;
    }
    sort(rk + 1, rk + n + 1, cmp);
    for (int i = 1; i <= n; i++)
    {
        if (dir[i] == 1)
        {
            cnt = (cnt - (p[i] + t) / m) % n;
        }
        else
        {
            cnt = (cnt - (p[i] - t - m + 1) / m) % n;
        }
        p[i] = ((p[i] + dir[i] * t) % m + m) % m;
    }
    sort(p + 1, p + n + 1);
    (cnt += n) %= n;
    rotate(rk + 1, rk + 1 + cnt, rk + n + 1);
    for (int i = 1; i <= n; i++)
    {
        ans[rk[i]] = p[i];
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i] + 1);
    }
    return 0;
}