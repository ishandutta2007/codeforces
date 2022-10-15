#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m, deg[100001], ind[100001];
vector<pair<int, int>> G[100001];
vector<int> ans;
bool vis[400001];
void dfs(int u)
{
    while (ind[u] < (int)G[u].size())
    {
        if (vis[G[u][ind[u]].second])
        {
            ind[u]++;
        }
        else
        {
            vis[G[u][ind[u]].second] = 1;
            int v = G[u][ind[u]].first;
            dfs(v);
            ans.push_back(u);
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].push_back(make_pair(v, i));
        G[v].push_back(make_pair(u, i));
        deg[u]++;
        deg[v]++;
    }
    int last = -1;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] & 1)
        {
            if (last == -1)
            {
                last = i;
            }
            else
            {
                G[last].push_back(make_pair(i, ++m));
                G[i].push_back(make_pair(last, m));
                last = -1;
            }
        }
    }
    if (m & 1)
    {
        G[1].push_back(make_pair(1, ++m));
        G[1].push_back(make_pair(1, m));
    }
    ans.push_back(1);
    dfs(1);
    printf("%d\n", m);
    for (int i = 0; i < (int)ans.size() - 1; i++)
    {
        if (i & 1)
        {
            printf("%d %d\n", ans[i], ans[i + 1]);
        }
        else
        {
            printf("%d %d\n", ans[i + 1], ans[i]);
        }
    }
    return 0;
}