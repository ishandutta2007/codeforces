#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
struct level
{
    int a, b, id;
} a[300001];
struct node
{
    int cnt, ls, rs;
    long long sum;
} t[10000001];
int n, m, tot = 1, b[300001];
void pushup(int x)
{
    t[x].cnt = t[t[x].ls].cnt + t[t[x].rs].cnt;
    t[x].sum = t[t[x].ls].sum + t[t[x].rs].sum;
}
void modify(int l, int r, int p, int val, int x)
{
    if (l == r)
    {
        t[x].cnt += val;
        t[x].sum += val * l;
        return;
    }
    int mid = (l + r) >> 1;
    if (p <= mid)
    {
        if (!t[x].ls)
        {
            t[x].ls = ++tot;
        }
        modify(l, mid, p, val, t[x].ls);
    }
    else
    {
        if (!t[x].rs)
        {
            t[x].rs = ++tot;
        }
        modify(mid + 1, r, p, val, t[x].rs);
    }
    pushup(x);
}
long long query(int l, int r, int k, int x)
{
    if (l == r)
    {
        return static_cast<long long>(k) * l;
    }
    int mid = (l + r) >> 1;
    if (k <= t[t[x].ls].cnt)
    {
        return query(l, mid, k, t[x].ls);
    }
    else
    {
        return t[t[x].ls].sum + query(mid + 1, r, k - t[t[x].ls].cnt, t[x].rs);
    }
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i].a >> a[i].b;
        a[i].id = i;
    }
    std::sort(a + 1, a + n + 1, [](const level &x, const level &y) -> bool {
        return x.b < y.b;
    });
    for (int i = 1; i <= n; i++)
    {
        modify(1, 1000000000, a[i].a, 1, 1);
    }
    long long ans = 1e18, tmp = 0;
    int pos = -1;
    for (int i = 1; i <= n && i <= m; i++)
    {
        if (m - i + 1 <= n)
        {
            if (long long t = tmp + query(1, 1000000000, m - i + 1, 1); ans > t)
            {
                ans = t;
                pos = i - 1;
            }
        }
        tmp += a[i].a;
        modify(1, 1000000000, a[i].a, -1, 1);
        modify(1, 1000000000, a[i].b - a[i].a, 1, 1);
    }
    if (m - n >= 0)
    {
        if (long long t = tmp + query(1, 1000000000, m - n, 1); ans > t)
        {
            ans = t;
            pos = n;
        }
    }
    std::cout << ans << '\n';
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    for (int i = 1; i <= pos; i++)
    {
        b[a[i].id] = 1;
        q.emplace(a[i].b - a[i].a, i);
    }
    for (int i = pos + 1; i <= n; i++)
    {
        q.emplace(a[i].a, i);
    }
    for (int i = 1; i <= m - pos; i++)
    {
        b[a[q.top().second].id]++;
        q.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        std::cout << b[i];
    }
    return 0;
}