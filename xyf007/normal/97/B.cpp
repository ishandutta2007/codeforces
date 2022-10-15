#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct node
{
    int x, y;
    bool operator<(const node a) const
    {
        if (x == a.x)
        {
            return y < a.y;
        }
        return x < a.x;
    }
    bool operator==(const node a) const
    {
        return x == a.x && y == a.y;
    }
} a[300001];
int n, m, tmp;
void solve(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1, X = a[mid].x;
    solve(l, mid);
    solve(mid + 1, r);
    for (int i = l; i <= r; i++)
    {
        a[++tmp] = (node){X, a[i].y};
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
    }
    sort(a + 1, a + n + 1);
    tmp = n;
    solve(1, n);
    sort(a + 1, a + tmp + 1);
    tmp = unique(a + 1, a + tmp + 1) - a - 1;
    printf("%d\n", tmp);
    for (int i = 1; i <= tmp; i++)
    {
        printf("%d %d\n", a[i].x, a[i].y);
    }
    return 0;
}