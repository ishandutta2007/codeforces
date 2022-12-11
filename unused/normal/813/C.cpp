#include <bits/stdc++.h>
using namespace std;

vector<int> graph[200005];
int depth[200005];
int parent[200005];
int dp[200005];

void dfs(int t, int p)
{
    dp[t] = depth[t];
    for (int nxt : graph[t])
    {
        if (nxt == p) continue;
        parent[nxt] = t;
        depth[nxt] = depth[t] + 1;
        dfs(nxt, t);
        dp[t] = max(dp[t], dp[nxt]);
    }
}

int main()
{
    int n, x;
    scanf("%d%d",&n,&x);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    int up = (depth[x] - 1) / 2;

    while (up--) x = parent[x];

    printf("%d\n", dp[x] * 2);
}