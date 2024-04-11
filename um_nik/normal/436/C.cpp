#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m, w, k;
string s[1010][11];
int g[1010][1010];
int ans;
vector<int> p[1010];
bool used[1010];

struct Item
{
    int v, u;
    int w;

    Item () {}
    Item (int v, int u, int w) : v(v), u(u), w(w) {}

    bool operator < (Item a)
    {
        return w < a.w;
    }
};
Item e[1010000];

int sz[1010];
int par[1010];

int get_par(int v)
{
    if (par[v] == -1)
        return v;
    int u = get_par(par[v]);
    par[v] = u;
    return u;
}

void dfs(int v)
{
    used[v] = 1;
    if (v != 0)
        printf("%d %d\n", v, par[v]);
    for (int i = 0; i < p[v].size(); i++)
    {
        int to = p[v][i];
        if (!used[to])
        {
            par[to] = v;
            dfs(to);
        }
    }
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d%d%d", &n, &m, &k, &w);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> s[i][j];
        g[0][i] = g[i][0] = n * m;
    }
    for (int i = 1; i <= k; i++)
        for (int j = i + 1; j <= k; j++)
        {
            for (int x = 0; x < n; x++)
                for (int y = 0; y < m; y++)
                    if (s[i][x][y] != s[j][x][y])
                        g[i][j] += w;
            g[j][i] = g[i][j];
        }
    n = k + 1;
    m = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            e[m++] = Item(i, j, g[i][j]);
    sort(e, e + m);
    for (int i = 0; i < n; i++)
    {
        sz[i] = 1;
        par[i] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        int v = get_par(e[i].v);
        int u = get_par(e[i].u);
        if (v != u)
        {
            ans += e[i].w;
            if (sz[v] > sz[u])
            {
                sz[v] += sz[u];
                par[u] = v;
            }
            else
            {
                sz[u] += sz[v];
                par[v] = u;
            }
            p[e[i].v].push_back(e[i].u);
            p[e[i].u].push_back(e[i].v);
        }
    }
    printf("%d\n", ans);
    dfs(0);
    return 0;
}