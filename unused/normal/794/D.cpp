#include <bits/stdc++.h>
using namespace std;

vector<int> graph[300005];
map<vector<int>, int> mp;
int id[300005], ans[300005];
int last = 1;

set<int> ng[300005];
pair<int, int> edges[300005];

void dfs(int t)
{
    ans[t] = last++;

    for (int nxt : ng[t])
    {
        if (ans[nxt]) continue;
        dfs(nxt);
        return;
    }
}

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) graph[i].push_back(i);
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);

        edges[i] = {a, b};
    }

    for (int i = 1; i <= n; i++)
    {
        sort(graph[i].begin(), graph[i].end());
        id[i] = mp.emplace(graph[i], mp.size()).first->second;
    }

    for (int i = 1; i <= m; i++)
    {
        int a, b; tie(a, b) = edges[i];
        if (id[a] == id[b]) continue;

        ng[id[a]].insert(id[b]);
        ng[id[b]].insert(id[a]);

        if (ng[id[a]].size() > 2 || ng[id[b]].size() > 2)
        {
            printf("NO\n");
            return 0;
        }
    }

    for (int i = 0; i < mp.size(); i++)
    {
        if (ng[i].size() == 2) continue;
        dfs(i);
        break;
    }

    for (int i = 0; i < mp.size(); i++) if (ans[i] == 0) { printf("NO\n"); return 0; }

    printf("YES\n");
    for (int i = 1; i <= n; i++) printf("%d ", ans[id[i]]);
    printf("\n");
}