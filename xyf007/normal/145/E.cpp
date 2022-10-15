#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <numeric>
struct Node
{
    int c0, c1, u, d;
} t[4000001];
int n, m, tag[4000001];
char s[1000001];
void Pushup(int x)
{
    t[x].c0 = t[x + x].c0 + t[x + x + 1].c0;
    t[x].c1 = t[x + x].c1 + t[x + x + 1].c1;
    t[x].u = std::max(t[x + x].c0 + t[x + x + 1].u, t[x + x].u + t[x + x + 1].c1);
    t[x].d = std::max(t[x + x].c1 + t[x + x + 1].d, t[x + x].d + t[x + x + 1].c0);
}
void Pushdown(int x)
{
    if (tag[x])
    {
        std::swap(t[x + x].c0, t[x + x].c1);
        std::swap(t[x + x + 1].c0, t[x + x + 1].c1);
        std::swap(t[x + x].u, t[x + x].d);
        std::swap(t[x + x + 1].u, t[x + x + 1].d);
        tag[x + x] ^= 1;
        tag[x + x + 1] ^= 1;
        tag[x] = 0;
    }
}
void Build(int l, int r, int x)
{
    if (l == r)
    {
        t[x].c0 = s[l] == '4';
        t[x].c1 = s[l] == '7';
        t[x].u = t[x].d = 1;
        return;
    }
    int mid = (l + r) >> 1;
    Build(l, mid, x + x);
    Build(mid + 1, r, x + x + 1);
    Pushup(x);
}
void Modify(int L, int R, int l, int r, int x)
{
    if (L <= l && r <= R)
    {
        std::swap(t[x].c0, t[x].c1);
        std::swap(t[x].u, t[x].d);
        tag[x] ^= 1;
        return;
    }
    Pushdown(x);
    int mid = (l + r) >> 1;
    if (L <= mid)
    {
        Modify(L, R, l, mid, x + x);
    }
    if (R > mid)
    {
        Modify(L, R, mid + 1, r, x + x + 1);
    }
    Pushup(x);
}
int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m >> (s + 1);
    Build(1, n, 1);
    char op[10];
    int l, r;
    for (int i = 1; i <= m; i++)
    {
        std::cin >> op;
        if (op[0] == 's')
        {
            std::cin >> l >> r;
            Modify(l, r, 1, n, 1);
        }
        else
        {
            std::cout << t[1].u << '\n';
        }
    }
    return 0;
}