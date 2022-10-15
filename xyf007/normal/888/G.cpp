#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
int n, a[200001], root, tot, ch[6000001][2], l[6000001], r[6000001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
void Insert(int &now, int x, int d)
{
    if (!now)
    {
        now = ++tot;
    }
    checkmin(l[now], x);
    checkmax(r[now], x);
    if (d < 0)
    {
        return;
    }
    Insert(ch[now][(a[x] >> d) & 1], x, d - 1);
}
int Query(int now, int v, int d)
{
    if (d < 0)
    {
        return 0;
    }
    int id = (v >> d) & 1;
    if (ch[now][id])
    {
        return Query(ch[now][id], v, d - 1);
    }
    else
    {
        return Query(ch[now][id ^ 1], v, d - 1) + (1 << d);
    }
}
long long Solve(int now, int d)
{
    if (d < 0)
    {
        return 0LL;
    }
    if (r[ch[now][0]] && r[ch[now][1]])
    {
        int min = 0x7fffffff;
        for (int i = l[ch[now][0]]; i <= r[ch[now][0]]; i++)
        {
            checkmin(min, Query(ch[now][1], a[i], d - 1));
        }
        return Solve(ch[now][0], d - 1) + Solve(ch[now][1], d - 1) + min + (1 << d);
    }
    if (r[ch[now][0]])
    {
        return Solve(ch[now][0], d - 1);
    }
    if (r[ch[now][1]])
    {
        return Solve(ch[now][1], d - 1);
    }
    return 0LL;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }
    std::sort(a + 1, a + n + 1);
    std::memset(l, 0x3f, sizeof(l));
    for (int i = 1; i <= n; i++)
    {
        Insert(root, i, 30);
    }
    std::cout << Solve(root, 30);
    return 0;
}