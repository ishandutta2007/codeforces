#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct rect
{
    int a, b, c, d;
} a[1001];
int n;
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
bool cmp1(rect x, rect y)
{
    if (x.a == y.a)
    {
        return x.c < y.c;
    }
    return x.a < y.a;
}
bool cmp2(rect x, rect y)
{
    if (x.b == y.b)
    {
        return x.d < y.d;
    }
    return x.b < y.b;
}
bool solve(int l, int r)
{
    if (l == r)
    {
        return 1;
    }
    int pos = -1, maxx = 0;
    sort(a + l, a + r + 1, cmp1);
    for (int i = l + 1; i <= r; i++)
    {
        checkmax(maxx, a[i - 1].c);
        if (maxx <= a[i].a)
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        return solve(l, pos - 1) && solve(pos, r);
    }
    sort(a + l, a + r + 1, cmp2);
    maxx = 0;
    for (int i = l + 1; i <= r; i++)
    {
        checkmax(maxx, a[i - 1].d);
        if (maxx <= a[i].b)
        {
            pos = i;
            break;
        }
    }
    if (pos != -1)
    {
        return solve(l, pos - 1) && solve(pos, r);
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d%d%d", &a[i].a, &a[i].b, &a[i].c, &a[i].d);
    }
    if (solve(1, n))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}