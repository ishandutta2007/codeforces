#include <bits/stdc++.h>
using namespace std;

const int N = 5001;
vector<int> g[N];
bool ok[N];
bool vis[N];
pair<int, int> cycle[N];
vector<int> sorted;
int n;

int find_cycle(int k)
{
    for(int i = 1; i <= n; i++)
        vis[i] = false;
    queue<pair<int, int>> q;
    q.push(make_pair(k, 1));
    while(!q.empty())
    {
        int v = q.front().first, d = q.front().second;
        q.pop();
        for(int u: g[v])
            if(u == k) return d;
            else if(!vis[u])
            {
                vis[u] = true;
                q.push(make_pair(u, d + 1));
            }
    }
    return 0;
}

void top_sort(int v)
{
    if(vis[v]) return;
    vis[v] = true;
    for(int u: g[v])
        top_sort(u);
    cycle[v].second = -sorted.size();
    sorted.push_back(v);
}

void dfs(int v)
{
    ok[v] = true;
    for(int u: g[v])
        if(!ok[u]) dfs(u);
}

int main()
{
    int m;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        top_sort(i);
    for(int i = 1; i <= n; i++)
        cycle[i].first = find_cycle(i);
    sort(cycle + 1, cycle + n + 1);
    int ans = n;
    for(int i = 1; i <= n; i++)
    {
        int v = sorted[-cycle[i].second], c = cycle[i].first;
        if(ok[v]) continue;
        if(c) ans += 998 * c + 1;
        dfs(v);
    }
    printf("%d\n", ans);
}