#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = 100100;
int n;
vector<int> g[N];
bool need[N], can[N];
bool a[N];
int V;

bool dfs(int v, int p)
{
    need[v] = 0;
    a[v] = 0;
    can[v] = 1;
    if ((int)g[v].size() == 1)
        return true;
    int cnt = 0;
    for (int u : g[v])
    {
        if (u == p) continue;
        if (!dfs(u, v)) return false;
        if (!can[u])
            can[v] = 0;
        if (!a[u]) continue;
        need[v] = a[v] = 1;
        if (need[u]) cnt++;
    }
    if (cnt > 1)
        can[v] = 0;
    if ((int)g[v].size() > 2)
        a[v] = 1;
    if ((int)g[v].size() > 3)
        need[v] = 1;
    if (!can[v])
    {
        V = v;
        return false;
    }
    return true;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    V = -1;
    for (int i = 0; V == -1 && i < n; i++)
        if ((int)g[i].size() > 2)
            V = i;
    if (V == -1)
    {
        printf("Yes\n");
        return 0;
    }
    for (int u : g[V])
    {
        if (!dfs(u, V)) break;
    }
    int cnt = 0;
    for (int u : g[V])
    {
        if (!dfs(u, V))
        {
            printf("No\n");
            return 0;
        }
        if (need[u]) cnt++;
    }
    if (cnt < 3)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}