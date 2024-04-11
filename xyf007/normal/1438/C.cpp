#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define id(x, y) (x - 1) * m + y
using namespace std;
struct edge
{
    int to, nxt;
} e[200001];
int t, n, m, a[101][101], head[20001], E, dfn[20001], low[20001], dep, stack[20001], top, col[20001], c;
bool vis[20001];
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
void tarjan(int u)
{
    dfn[u] = low[u] = ++dep;
    vis[u] = true;
    stack[++top] = u;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            checkmin(low[u], low[v]);
        }
        else
        {
            if (vis[v])
            {
                checkmin(low[u], dfn[v]);
            }
        }
    }
    if (dfn[u] == low[u])
    {
        col[u] = ++c;
        vis[u] = false;
        while (stack[top] != u)
        {
            col[stack[top]] = c;
            vis[stack[top--]] = false;
        }
        top--;
    }
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> t;
    while (t--)
    {
        E = dep = top = c = 0;
        memset(head, -1, sizeof(head));
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(stack, 0, sizeof(stack));
        memset(col, 0, sizeof(col));
        memset(vis, false, sizeof(vis));
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> a[i][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i > 1)
                {
                    if (a[i][j] == a[i - 1][j])
                    {
                        add(id(i - 1, j), id(i, j) + n * m);
                        add(id(i - 1, j) + n * m, id(i, j));
                        add(id(i, j), id(i - 1, j) + n * m);
                        add(id(i, j) + n * m, id(i - 1, j));
                    }
                    if (a[i][j] + 1 == a[i - 1][j])
                    {
                        add(id(i, j) + n * m, id(i - 1, j) + n * m);
                        add(id(i - 1, j), id(i, j));
                    }
                }
                if (i < n)
                {
                    if (a[i][j] + 1 == a[i + 1][j])
                    {
                        add(id(i, j) + n * m, id(i + 1, j) + n * m);
                        add(id(i + 1, j), id(i, j));
                    }
                }
                if (j > 1)
                {
                    if (a[i][j] == a[i][j - 1])
                    {
                        add(id(i, j), id(i, j - 1) + n * m);
                        add(id(i, j) + n * m, id(i, j - 1));
                        add(id(i, j - 1), id(i, j) + n * m);
                        add(id(i, j - 1) + n * m, id(i, j));
                    }
                    if (a[i][j] + 1 == a[i][j - 1])
                    {
                        add(id(i, j) + n * m, id(i, j - 1) + n * m);
                        add(id(i, j - 1), id(i, j));
                    }
                }
                if (j < m)
                {
                    if (a[i][j] + 1 == a[i][j + 1])
                    {
                        add(id(i, j) + n * m, id(i, j + 1) + n * m);
                        add(id(i, j + 1), id(i, j));
                    }
                }
            }
        }
        for (int i = 1; i <= 2 * n * m; i++)
        {
            if (!dfn[i])
            {
                tarjan(i);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[i][j] + (col[id(i, j)] > col[id(i, j) + n * m]) << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}