#include <bits/stdc++.h>
using namespace std;

vector<int> graph[100005];
int col[100005];
int cnt[3];

void dfs(int t, int col)
{
    ::col[t] = col;
    cnt[col]++;
    for (int nxt : graph[t])
    {
        if (::col[nxt]) continue;
        dfs(nxt, col ^ 3);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1, 1);

    printf("%lld\n", cnt[1] * 1ll * cnt[2] - (n - 1));
}