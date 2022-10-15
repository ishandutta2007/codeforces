#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;
struct edge
{
    int to, nxt, cost;
    edge(int to = 0, int nxt = -1, int cost = 0) : to(to), nxt(nxt), cost(cost) {}
} e[200001];
int n, a[201], not_prime[100001], E, head[100001], dep[100001], cur[100001], s, t;
vector<int> odd, even, cir;
vector<vector<int> > Ans;
bool vis[201];
void add(int f, int t, int c)
{
    e[E].to = t;
    e[E].cost = c;
    e[E].nxt = head[f];
    head[f] = E++;
}
void init()
{
    not_prime[1] = 1;
    for (int i = 2; i * i <= 100000; i++)
    {
        if (not_prime[i])
        {
            continue;
        }
        for (int j = i * i; j <= 100000; j += i)
        {
            not_prime[j] = 1;
        }
    }
}
bool bfs()
{
    queue<int> q;
    memset(dep, 0, sizeof(dep));
    for (int i = 0; i <= n + 1; i++)
    {
        cur[i] = head[i];
    }
    q.push(s);
    dep[s] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
            int v = e[i].to;
            if (e[i].cost && !dep[v])
            {
                dep[v] = dep[u] + 1;
                q.push(v);
            }
        }
    }
    return dep[t];
}
int dfs(int u, int sum)
{
    if (u == t || !sum)
    {
        return sum;
    }
    int ans = 0;
    for (int i = cur[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (dep[v] == dep[u] + 1 && e[i].cost)
        {
            int minn = dfs(v, min(sum, e[i].cost));
            if (minn)
            {
                e[i].cost -= minn;
                e[i ^ 1].cost += minn;
                ans += minn;
                sum -= minn;
                if (!sum)
                {
                    break;
                }
            }
        }
        cur[u] = e[i].nxt;
    }
    if (!ans)
    {
        dep[u] = -1;
    }
    return ans;
}
int dinic()
{
    int ans = 0;
    while (bfs())
    {
        ans += dfs(s, 2e9);
    }
    return ans;
}
void getcir(int u)
{
    cir.push_back(u);
    vis[u] = 1;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (vis[v] || !e[i ^ (a[u] & 1)].cost)
        {
            continue;
        }
        getcir(v);
    }
}
int main(int argc, char const *argv[])
{
    init();
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    s = 0;
    t = n + 1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] & 1)
        {
            odd.push_back(i);
            add(s, i, 2);
            add(i, s, 0);
        }
        else
        {
            even.push_back(i);
            add(i, t, 2);
            add(t, i, 0);
        }
    }
    if (odd.size() != even.size())
    {
        printf("Impossible");
        return 0;
    }
    for (auto i : odd)
    {
        for (auto j : even)
        {
            if (!not_prime[a[i] + a[j]])
            {
                add(i, j, 1);
                add(j, i, 0);
            }
        }
    }
    if (dinic() != n)
    {
        printf("Impossible");
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
        {
            continue;
        }
        cir.clear();
        getcir(i);
        Ans.push_back(cir);
    }
    printf("%d\n", (int)Ans.size());
    for (auto i : Ans)
    {
        printf("%d ", (int)i.size());
        for (auto j : i)
        {
            printf("%d ", j);
        }
        printf("\n");
    }
    return 0;
}//