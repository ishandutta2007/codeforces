#include <bits/stdc++.h>

using namespace std;

const int maxn = 100005;

vector <int> ke[maxn];

int n, m;

bool vis[maxn];

void nhap()
{
    scanf("%d%d", &n, &m);
    for(int i=1; i<=m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
}

void dfs(int u, int dis, int &L, int &d)
{
    if (dis > L)
    {
        L = dis;
        d = u;
    }
    for(int j=0; j<ke[u].size(); j++)
    {
        int v = ke[u][j];
        if (vis[v] == 0)
        {
            vis[v] = 1;
            dfs(v, dis+1, L, d);
        }
    }
}

void tinh()
{
    memset(vis, 0, sizeof(vis));
    int l = 0, d = 1;
    vis[1] = 1;
    dfs(1, 0, l, d);
    
    memset(vis, 0, sizeof(vis));
    l = 0;
    vis[d] = 1;
    dfs(d, 0, l, d);
    
    printf("%d\n", l);
}

int main()
{
    nhap();
    tinh();
    return 0;
}