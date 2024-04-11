#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int low[200001];
int d[200001];
vector<int> g[200001];
int r[200001];
int up[200001];
vector<pair<int, int>> bridges;

int Find(int k)
{
    if(r[k] != k) r[k] = Find(r[k]);
    return r[k];
}

void Union(int a, int b)
{
    r[Find(a)] = Find(b);
}

void dfs(int v, int prev)
{
    low[v] = d[v] = d[prev] + 1;
    for(auto u: g[v])
    {
    if(u == prev)
    {
        up[v] = u;
        prev = 0;
        continue;
    }
    if(d[u])
    {
        low[v] = min(low[v], d[u]);
        Union(u, v);
    }
    else
    {
        dfs(u, v);
        low[v] = min(low[v], low[u]);
    }
    }
    if(up[v] != 0)
    if(low[v] == d[v]) bridges.push_back(make_pair(up[v], v));
    else Union(up[v], v);
}

vector<int> tree[200001];
int in[200001];
int out[200001];
const int LOGN = 18;
int jump[LOGN + 1][200001];
int upCount[200001];
int downCount[200001];

void dfsTree(int v)
{
    static int time;
    in[v] = ++time;
    for(int u: tree[v])
    {
    if(in[u]) continue;
    jump[0][u] = v;
    dfsTree(u);
    }
    out[v] = ++time;
}

bool ancestor(int a, int b)
{
    return a == 0 || (in[a] <= in[b] && out[a] >= out[b]);
}

int lca(int a, int b)
{
    for(int i = LOGN; i >= 0; i--)
    if(!ancestor(jump[i][a], b))
        a = jump[i][a];
    if(!ancestor(a, b)) a = jump[0][a];
    return a;
}

bool check(int v, int prev = 0)
{
    for(int u: tree[v])
    {
    if(u == prev) continue;
    if(!check(u, v)) return false;
    upCount[v] += upCount[u];
    downCount[v] += downCount[u];
    }
    if(upCount[v] && downCount[v])
    return false;
    return true;
}

int main()
{
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    while(m--)
    {
    int a, b;
    scanf("%d %d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    r[i] = i;
    for(int i = 1; i <= n; i++)
    if(d[i] == 0)
    {
        d[i] = 1;
        dfs(i, 0);
    }
    for(auto p: bridges)
    {
    int a = Find(p.first), b = Find(p.second);
    if(a == b) continue;
    tree[a].push_back(b);
    tree[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
    if(r[i] == i && in[i] == 0)
        dfsTree(i);
    for(int i = 1; i <= LOGN; i++)
    for(int j = 1; j <= n; j++)
        jump[i][j] = jump[i-1][jump[i-1][j]];
    while(q--)
    {
    int a, b;
    scanf("%d %d", &a, &b);
    a = Find(a); b = Find(b);
    int c = lca(a, b);
    if(c == 0)
    {
        puts("No");
        return 0;
    }
    upCount[c]--;
    downCount[c]--;
    upCount[a]++;
    downCount[b]++;
    }
    for(int i = 1; i <= n; i++)
    if(r[i] == i && jump[0][i] == 0 && !check(i))
    {
        puts("No");
        return 0;
    }
    puts("Yes");
}