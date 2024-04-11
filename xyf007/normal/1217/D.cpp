#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
struct edge
{
    int from, to, nxt, col;
    edge(int from = 0, int to = 0, int nxt = -1, int col = 0) : from(from), to(to), nxt(nxt), col(col) {}
} e[5001];
int n, m, E, head[5001], ind[5001], ans = 1;
void add(int f, int t)
{
    e[E].from = f;
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (!ind[i])
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            e[i].col = 1;
            int v = e[i].to;
            if (!--ind[v])
            {
                q.push(v);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        ind[v]++;
    }
    topsort();
    for (int i = 0; i < m; i++)
    {
        if (!e[i].col)
        {
            e[i].col = e[i].from < e[i].to ? 1 : 2;
        }
        if (e[i].col == 2)
        {
            ans = 2;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < m; i++)
    {
        printf("%d ", e[i].col);
    }
    return 0;
}