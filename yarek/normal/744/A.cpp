#include <bits/stdc++.h>
using namespace std;

const int N = 1001;
vector<int> g[N];
bool vis[N];
int c[N];

int dfs(int v)
{
    if(vis[v]) return 0;
    vis[v] = true;
    int ans = 1;
    for(int u: g[v])
        ans += dfs(u);
    return ans;
}

int main()
{
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < k; i++)
        scanf("%d", c + i);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int ans = -m, mx = 0;
    for(int i = 0; i < k; i++)
    {
        int s = dfs(c[i]);
        ans += s * (s - 1) / 2;
        mx = max(mx, s);
    }
    ans -= mx * (mx - 1) / 2;
    for(int i = 1; i <= n; i++)
        if(!vis[i]) mx++;
    ans += mx * (mx - 1) / 2;
    printf("%d\n", ans);
}