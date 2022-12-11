#include <bits/stdc++.h>
using namespace std;

vector<int> col[300005];
vector<int> graph[300005];
int ans[300005];

void dfs(int t, int p)
{
    set<int> used;
    int last = 1;

    for (int x : col[t])
    {
        if (ans[x]) used.insert(ans[x]);
    }

    for (int x : col[t])
    {
        if (ans[x]) continue;
        while (used.count(last)) ++last;
        ans[x] = last++;
    }

    for (int nxt : graph[t])
    {
        if (nxt == p) continue;
        dfs(nxt, t);
    }
}

int main()
{
    int n, m;
    int maxcol = 1;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++)
    {
        int s;
        scanf("%d",&s);
        col[i].resize(s);
        maxcol = max(maxcol, s);
        for (int j = 0; j < s; j++) scanf("%d", &col[i][j]);
        sort(col[i].begin(), col[i].end());
    }

    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, -1);

    printf("%d\n", maxcol);
    for (int i = 1; i <= m; i++) printf("%d ", max(ans[i], 1));
    printf("\n");
}