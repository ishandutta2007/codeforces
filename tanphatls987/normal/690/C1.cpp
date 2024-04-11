#include <bits/stdc++.h>

using namespace std;

bool vis[1010];
vector <int> ke[1010];
int n, m;

void nhap()
{
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}

void dfs(int u)
{
    for(int j=0; j<ke[u].size(); j++)
    {
        int v = ke[u][j];
        if (!vis[v])
        {
            vis[v] = 1;
            dfs(v);
        }
    }
}

int tinh()
{
    memset(vis, 0, sizeof(vis));
    vis[1] = 1;
    dfs(1);
    int res = 0;
    for(int i=1; i<=n; i++)
        res += vis[i];
    return res;
}

int main()
{
    nhap();
    
    if (m == n-1 && tinh() == n)
        printf("yes\n");
    else printf("no\n");
    return 0;
}