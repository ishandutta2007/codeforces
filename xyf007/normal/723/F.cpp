#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
struct edge
{
    int to, nxt;
    edge(int to = 0, int nxt = -1) : to(to), nxt(nxt) {}
} e[800001];
int n, m, s, t, ds, dt, E, head[200001], fa[200001], ls[200001], lt[200001];
vector<pair<int, int> > ans;
void init()
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
    }
}
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
int find(int x)
{
    if (x == fa[x])
    {
        return x;
    }
    return fa[x] = find(fa[x]);
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    init();
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    scanf("%d%d%d%d", &s, &t, &ds, &dt);
    for (int i = 1; i <= n; i++)
    {
        if (i == s || i == t)
        {
            continue;
        }
        for (int j = head[i]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to, fx, fy;
            if (v == s || v == t)
            {
                continue;
            }
            fx = find(i);
            fy = find(v);
            if (fx != fy)
            {
                fa[fx] = fy;
                ans.push_back(make_pair(i, v));
            }
        }
    }
    for (int i = head[s]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to, fv;
        if (v == t)
        {
            continue;
        }
        fv = find(v);
        ls[fv] = v;
    }
    for (int i = head[t]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to, fv;
        if (v == s)
        {
            continue;
        }
        fv = find(v);
        lt[fv] = v;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ls[i] && !lt[i])
        {
            ds--;
            int fx = find(s), fy = find(i);
            fa[fx] = fy;
            ans.push_back(make_pair(s, ls[i]));
        }
        if (!ls[i] && lt[i])
        {
            dt--;
            int fx = find(t), fy = find(i);
            fa[fx] = fy;
            ans.push_back(make_pair(t, lt[i]));
        }
        if (ds < 0 || dt < 0)
        {
            printf("No");
            return 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ls[i] && lt[i])
        {
            if (ds)
            {
                int fx = find(s), fy = find(i);
                if (fx == fy)
                {
                    continue;
                }
                fa[fx] = fy;
                ds--;
                ans.push_back(make_pair(s, ls[i]));
            }
            if (dt)
            {
                int fx = find(t), fy = find(i);
                if (fx == fy)
                {
                    continue;
                }
                fa[fx] = fy;
                dt--;
                ans.push_back(make_pair(t, lt[i]));
            }
            if (find(s) != find(i) || find(i) != find(t))
            {
                printf("No");
                return 0;
            }
        }
    }
    if (find(s) != find(t))
    {
        bool f = 0;
        for (int i = head[s]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (v == t)
            {
                f = 1;
                break;
            }
        }
        if (ds && dt && f)
        {
            ans.push_back(make_pair(s, t));
        }
        else
        {
            printf("No");
            return 0;
        }
    }
    if ((int)ans.size() != n - 1)
    {
        printf("No");
        return 0;
    }
    printf("Yes\n");
    for (auto i : ans)
    {
        printf("%d %d\n", i.first, i.second);
    }
    return 0;
}