#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge
{
    int to, nxt;
    edge(int to = 0, int nxt = -1) : to(to), nxt(nxt) {}
} e[2000001];
int n, k, E, head[1000001], dfn[1000001], sz[1000001], dep[1000001], f[1000001], tot, t[1000001], now;
bool vis[1000001];
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void modify(int x, int val)
{
    while (x <= n)
    {
        t[x] += val;
        x += x & -x;
    }
}
int get(int x)
{
    int s = 0;
    while (x)
    {
        s += t[x];
        x -= x & -x;
    }
    return s;
}
void dfs(int u, int fa)
{
    dfn[u] = ++tot;
    dep[u] = dep[fa] + 1;
    sz[u] = 1;
    f[u] = fa;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
        sz[u] += sz[v];
    }
}
void check(int x)
{
    if (dep[x] - get(dfn[x]) > n - k - now)
    {
        return;
    }
    for (int i = x; i < n; i = f[i])
    {
        if (vis[i])
        {
            break;
        }
        vis[i] = 1;
        modify(dfn[i], 1);
        modify(dfn[i] + sz[i], -1);
        now++;
    }
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(n, n);
    vis[n] = 1;
    for (int i = n - 1; i >= 1; i--)
    {
        if (!vis[i])
        {
            check(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            printf("%d ", i);
        }
    }
    return 0;
}