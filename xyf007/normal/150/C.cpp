#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
struct Node
{
    double sum, lmax, rmax, max;
    Node(double sum = 0.0, double lmax = 0.0, double rmax = 0.0, double max = 0.0) : sum(sum), lmax(lmax), rmax(rmax), max(max) {}
} t[600001];
int n, m, c, x[150001], p[150001];
double a[150001];
void Merge(Node &x, Node ls, Node rs)
{
    x.sum = ls.sum + rs.sum;
    x.lmax = std::max(ls.lmax, ls.sum + rs.lmax);
    x.rmax = std::max(rs.rmax, rs.sum + ls.rmax);
    x.max = std::max(std::max(ls.max, rs.max), ls.rmax + rs.lmax);
}
void Pushup(int x)
{
    Merge(t[x], t[x + x], t[x + x + 1]);
}
void Build(int l, int r, int x)
{
    if (l == r)
    {
        t[x].sum = a[l];
        t[x].lmax = t[x].rmax = t[x].max = std::max(a[l], 0.0);
        return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x);
    Build(mid + 1, r, x + x + 1);
    Pushup(x);
}
Node Query(int L, int R, int l, int r, int x)
{
    if (L <= l && r <= R)
    {
        return t[x];
    }
    int mid = (l + r) >> 1;
    if (R <= mid)
    {
        return Query(L, R, l, mid, x + x);
    }
    if (L > mid)
    {
        return Query(L, R, mid + 1, r, x + x + 1);
    }
    Node ret;
    Merge(ret, Query(L, R, l, mid, x + x), Query(L, R, mid + 1, r, x + x + 1));
    return ret;
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        std::cin >> x[i];
    }
    for (int i = 1; i < n; i++)
    {
        std::cin >> p[i];
    }
    std::adjacent_difference(x + 2, x + n + 1, a + 1);
    std::transform(a + 1, a + n, p + 1, a + 1, [](const double &x, const int &y) -> double { return x / 2 - y / 100.0 * c; });
    Build(1, n - 1, 1);
    double ans = 0.0;
    for (int i = 1; i <= m; i++)
    {
        int l, r;
        std::cin >> l >> r;
        ans += Query(l, r - 1, 1, n - 1, 1).max;
    }
    std::cout << std::setprecision(8) << std::fixed << ans << '\n';
    return 0;
}