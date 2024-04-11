#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
struct edge
{
    int to, nxt;
    edge(int to = 0, int nxt = -1) : to(to), nxt(nxt) {}
} e[600001];
int n, m, E, head[100001], ans[100001];
set<int> a, b, c;
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        a.insert(i);
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for (set<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        int u = *it;
        for (int j = head[u]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to;
            if (a.count(v))
            {
                b.insert(v);
                a.erase(v);
            }
        }
    }
    for (set<int>::iterator it = b.begin(); it != b.end(); it++)
    {
        int u = *it;
        for (int j = head[u]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to;
            if (b.count(v))
            {
                c.insert(v);
                b.erase(v);
            }
        }
    }
    for (set<int>::iterator it = c.begin(); it != c.end(); it++)
    {
        int u = *it;
        for (int j = head[u]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to;
            if (c.count(v))
            {
                printf("-1");
                return 0;
            }
        }
    }
    if (!a.size() || !b.size() || !c.size())
    {
        printf("-1");
        return 0;
    }
    if (a.size() * b.size() + a.size() * c.size() + b.size() * c.size() != m)
    {
        printf("-1");
        return 0;
    }
    for (set<int>::iterator it = a.begin(); it != a.end(); it++)
    {
        int u = *it;
        ans[u] = 1;
    }
    for (set<int>::iterator it = b.begin(); it != b.end(); it++)
    {
        int u = *it;
        ans[u] = 2;
    }
    for (set<int>::iterator it = c.begin(); it != c.end(); it++)
    {
        int u = *it;
        ans[u] = 3;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}