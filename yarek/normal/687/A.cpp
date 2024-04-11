#include <bits/stdc++.h>
using namespace std;

const int N = 100001;
vector<int> g[N];
int col[N];
vector<int> ans[3];

bool dfs(int v, int c)
{
    if(col[v]) return col[v] == c;
    col[v] = c;
    ans[c].push_back(v);
    for(int u: g[v])
        if(!dfs(u, 3 - c))
            return false;
    return true;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(!col[i] && !dfs(i, 1))
        {
            puts("-1");
            return 0;
        }
    for(int i = 1; i <= 2; i++)
    {
        printf("%d\n", ans[i].size());
        for(int x: ans[i])
            printf("%d ", x);
        puts("");
    }
}