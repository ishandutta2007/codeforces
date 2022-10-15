#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, k;
vector<int> G[100001];
bool vis[100001];
void dfs(int u)
{
    vis[u] = 1;
    for (int i = 0; i < (int)G[u].size(); i++)
    {
        int v = G[u][i];
        if (vis[v])
        {
            continue;
        }
        dfs(v);
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    int sum = n;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            sum--;
            dfs(i);
        }
    }
    printf("%d", k - sum);
    return 0;
}