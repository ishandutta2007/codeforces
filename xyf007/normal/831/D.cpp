#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct person
{
    int l, r;
    bool operator<(const person a) const
    {
        if (l == a.l)
        {
            return r < a.r;
        }
        return l < a.l;
    }
} c[1001];
int n, k, p, a[1001], b[2001];
bool check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        int t = x - abs(a[i] - p);
        if (t < 0)
        {
            return 0;
        }
        c[i].l = min(a[i], p) - t / 2;
        c[i].r = max(a[i], p) + t / 2;
    }
    sort(c + 1, c + n + 1);
    int tmp = 1;
    for (int i = 1; i <= n; i++)
    {
        if (tmp > k)
        {
            return 0;
        }
        while (tmp < k && b[tmp] < c[i].l)
        {
            tmp++;
        }
        if ((tmp == k && b[tmp] < c[i].l) || b[tmp] > c[i].r)
        {
            return 0;
        }
        tmp++;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d%d", &n, &k, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + k + 1);
    int l = 0, r = 2e9, best = -1;
    while (l <= r)
    {
        int mid = l + (r - l >> 1);
        if (check(mid))
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    printf("%d", best);
    return 0;
}