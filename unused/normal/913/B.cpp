#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1001];

void dfs(int t)
{
    if (graph[t].empty()) return;
    else
    {
        int cnt = 0;

        for (int nxt : graph[t])
        {
            dfs(nxt);
            if (graph[nxt].empty()) ++cnt;
        }

        if (cnt < 3) 
        {
            printf("No\n");
            exit(0);
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d",&x);
        graph[x].push_back(i);
    }

    dfs(1);

    printf("Yes\n");
}