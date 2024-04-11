#include <bits/stdc++.h>
using namespace std;

const int N = 300001;
vector<int> c[N];
int size[N];
int par[N];
int ans[N];
bool vis[N];

void dfs(int v)
{
    size[v] = 1;
    pair<int, int> best(0, 0);
    for(int u: c[v])
    {
        dfs(u);
        size[v] += size[u];
        best = max(best, make_pair(size[u], u));
    }
    if(c[v].empty()) ans[v] = v;
    else
    {
        ans[v] = ans[best.second];
        while(size[ans[v]] * 2 < size[v])
            ans[v] = par[ans[v]];
    }
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 2; i <= n; i++)
    {
        scanf("%d", par + i);
        c[par[i]].push_back(i);
    }
    dfs(1);
    while(q--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
}