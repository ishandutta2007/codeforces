#include <bits/stdc++.h>
using namespace std;

const int N = 300001, LOGN = 20;
vector<pair<int, int>> g[N];
int to_parent[N];
bool marked[N];

vector<int> ans;

int dfs(int v, int prev)
{
    int m = marked[v];
    for(auto u: g[v])
        if(u.first == prev)
            to_parent[v] = u.second;
        else m ^= dfs(u.first, v);
    if(m) ans.push_back(to_parent[v]);
    return m;
}

int r[N];
int p[N];
int d[N];

int Find(int k)
{
    if(r[k] != k)
        r[k] = Find(r[k]);
    return r[k];
}

bool Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if(a != b)
    {
        r[a] = b;
        p[b] ^= p[a];
        return true;
    }
    return false;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", d + i);
        r[i] = i;
        if(d[i] == 1)
        {
            p[i] ^= 1;
            marked[i] = true;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(Union(a, b))
        {
            g[a].emplace_back(b, i);
            g[b].emplace_back(a, i);
        }
    }
    for(int i = 1; i <= n; i++)
        if(d[i] == -1 && p[Find(i)])
        {
            marked[i] = true;
            p[Find(i)] = 0;
        }
    for(int i = 1; i <= n; i++)
        if(r[i] == i)
            if(p[i])
            {
                puts("-1");
                return 0;
            }
            else dfs(i, 0);
    printf("%d\n", ans.size());
    for(auto x: ans)
        printf("%d\n", x);
}