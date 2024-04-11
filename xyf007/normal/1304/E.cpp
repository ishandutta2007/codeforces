#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge
{
    int to, nxt;
    edge(int to = 0, int nxt = -1) : to(to), nxt(nxt) {}
} e[200001];
int n, q, head[100001], E, dep[100001], f[100001][21];
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for (int i = 1; i <= 20; i++)
    {
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
    }
}
int get(int x, int y)
{
    int ans = 0;
    if (dep[x] > dep[y])
    {
        swap(x, y);
    }
    for (int i = 20; i >= 0; i--)
    {
        if (dep[f[y][i]] >= dep[x])
        {
            y = f[y][i];
            ans += (1 << i);
        }
    }
    if (x == y)
    {
        return ans;
    }
    for (int i = 20; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
            ans += (1 << (i + 1));
        }
    }
    return ans + 2;
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    memset(head, -1, sizeof(head));
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    scanf("%d", &q);
    while (q--)
    {
        int x, y, a, b, k, t1, t2, ans = 2e9;
        scanf("%d%d%d%d%d", &x, &y, &a, &b, &k);
        t1 = get(a, b);
        t2 = min(get(a, x) + get(b, y), get(b, x) + get(a, y)) + 1;
        if (!((t1 ^ k) & 1))
        {
            checkmin(ans, t1);
        }
        if (!((t2 ^ k) & 1))
        {
            checkmin(ans, t2);
        }
        if (ans <= k)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
    return 0;
}