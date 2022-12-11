#include <bits/stdc++.h>
using namespace std;

bool p[300005], vis[300005];
set<pair<int, int>> graph[300005];
bool ans[300005];

int main()
{
    int n, k, d;
    scanf("%d%d%d", &n, &k, &d);

    for (int i = 1; i <= k; i++)
    {
        int t;
        scanf("%d",&t);
        p[t] = true;
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].emplace(b, i);
        graph[b].emplace(a, i);
    }

    queue<tuple<int, int, int>> que;

    for (int i = 1; i <= n; i++)
    {
        if (p[i])
        {
            vis[i] = true;
            que.emplace(i, -1, 0);
        }
    }

    while (que.empty() == false)
    {
        int t, p, w;
        tie(t, p, w) = que.front();
        que.pop();

        for (auto itr = graph[t].begin(); itr != graph[t].end();)
        {
            auto nxt = *itr;
            if (nxt.first == p) { ++itr; continue; }

            if (vis[nxt.first] || w == d)
            {
                ans[nxt.second] = true;
                itr = graph[t].erase(itr);
                graph[nxt.first].erase({t, nxt.second});
            }
            else
            {
                vis[nxt.first] = true;
                que.emplace(nxt.first, t, w + 1);
                ++itr;
            }
        }
    }

    printf("%d\n", accumulate(ans + 1, ans + n, 0));
    for (int i = 1; i < n; i++) if (ans[i]) printf("%d ", i);
    printf("\n");
}