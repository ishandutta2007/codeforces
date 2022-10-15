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
} e[100001];
int n, m, E = 1, head[100001], ind[100001], dfn, df[100001], sum;
vector<int> ans;
void add(int f, int t, int c)
{
    e[E].to = t;
    e[E].cost = c;
    e[E].nxt = head[f];
    head[f] = E++;
}
bool check(int x)
{
    dfn = 0;
    memset(ind, 0, sizeof(ind));
    memset(df, 0, sizeof(df));
    sum = 0;
    queue<int> q;
    for (int i = 1; i <= E; i++)
    {
        if (e[i].cost > x)
        {
            ind[e[i].to]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!ind[i])
        {
            q.push(i);
            df[i] = ++dfn;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i != -1; i = e[i].nxt)
        {
        	if (e[i].cost <= x)
        	{
        		continue;
			}
            int v = e[i].to;
            ind[v]--;
            if (!ind[v])
            {
                df[v] = ++dfn;
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i])
        {
            return 0;
        }
    }
    ans.clear();
    for (int i = 1; i <= n; i++)
    {
        for (int j = head[i]; j != -1; j = e[j].nxt)
        {
            int v = e[j].to;
            if (df[i] > df[v] && e[j].cost <= x)
            {
                sum++;
                ans.push_back(j);
            }
        }
    }
    return 1;
}
int main()
{
    memset(head, -1, sizeof(head));
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        add(u, v, c);
    }
    int l = 0, r = 2e9, best = -1;
    while (l <= r)
    {
        int mid = l + ((r - l) >> 1);
        if (check(mid))
        {
            best = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    check(best);
    printf("%d %d\n", best, sum);
    for (vector<int>::iterator it = ans.begin(); it != ans.end(); it++)
    {
        printf("%d ", *it);
    }
    return 0;
}