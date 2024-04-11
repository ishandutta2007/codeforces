#include <bits/stdc++.h>
using namespace std;

int v[300005];
int n, k;

int fw[300005];

void update(int pos)
{
    ++pos;
    while (pos < 300005)
    {
        fw[pos]++;
        pos += pos & -pos;
    }
}

int query(int pos)
{
    pos = min(pos, 300003);
    int ret = 0;
    for (++pos; pos; pos -= pos & -pos)
        ret += fw[pos];
    return ret;
}

bool check(int x)
{
    memset(fw, 0, sizeof(fw));

    update(n);

    for (int i = n - k; i >= 0; i--)
    {
        int p = lower_bound(v, v + n, v[i] + x + 1) - v;
        if (p >= i + k && query(p) - query(i + k - 1))
        {
            if (i == 0) return true;
            else update(i);
        }
        else
        {
            if (i == 0) return false;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0; i < n; i++) scanf("%d",&v[i]);

    sort(v, v + n);

    int lo = 0, hi = 1e9, ans = hi + 1;
    while (lo <= hi)
    {
        int mid = lo + hi >> 1;
        if (check(mid))
        {
            ans = mid;
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    printf("%d\n", ans);
}