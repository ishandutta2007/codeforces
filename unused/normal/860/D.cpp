#include <bits/stdc++.h>
using namespace std;

set<int> graph[200005];
bool visit[200005];
int depth[200005];
int parent[200005];
int degree[200005];

vector<tuple<int, int, int>> ans;
priority_queue<pair<int, int>> que;

void dfs(int t)
{
    visit[t] = true;

    for (int nxt : graph[t])
    {
        if (visit[nxt]) continue;
        parent[nxt] = t;
        depth[nxt] = depth[t] + 1;
        dfs(nxt);
        ++degree[t];
    }

    if (parent[t] && degree[t] == 0) que.emplace(depth[t], t);
}

void process(int t)
{
    dfs(t);

    while (que.empty() == false)
    {
        int x = que.top().second; que.pop();
        int p = parent[x];

        if (graph[x].size() & 1)
        {
            graph[x].erase(p);

            while (graph[x].empty() == false)
            {
                ans.emplace_back(*graph[x].begin(), x, *graph[x].rbegin());
                graph[*graph[x].begin()].erase(x);
                graph[*graph[x].rbegin()].erase(x);
                graph[x].erase(graph[x].begin());
                graph[x].erase(prev(graph[x].end()));
            }

            graph[x].insert(p);
        }
        else
        {
            while (graph[x].empty() == false)
            {
                ans.emplace_back(*graph[x].begin(), x, *graph[x].rbegin());
                graph[*graph[x].begin()].erase(x);
                graph[*graph[x].rbegin()].erase(x);
                graph[x].erase(graph[x].begin());
                graph[x].erase(prev(graph[x].end()));
            }
        }

        if (p != t && --degree[p] == 0)
        {
            que.emplace(depth[p], p);
            assert(graph[p].count(parent[p]));
        }
    }

    while (graph[t].size() >= 2)
    {
        ans.emplace_back(*graph[t].begin(), t, *graph[t].rbegin());
        graph[t].erase(graph[t].begin());
        graph[t].erase(prev(graph[t].end()));
    }
}

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].insert(b);
        graph[b].insert(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (visit[i]) continue;

        process(i);
    }

    printf("%zd\n", ans.size());
    for (auto &e : ans)
    {
        printf("%d %d %d\n", get<0>(e), get<1>(e), get<2>(e));
    }
}