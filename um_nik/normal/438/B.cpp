#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

int n, m;
ll ans;
vector<int> g[100100];
bool used[100100];
pair<int, int> z[100100];
int perm[100100];
ll cost[100100];

int par[100100];
ll sz[100100];

int get_par(int v)
{
    if (par[v] == -1)
        return v;
    int u = get_par(par[v]);
    return par[v] = u;
}

void my_union(int v, int u)
{
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
    return;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &z[i].first);
        z[i].second = i + 1;
    }
    sort(z, z + n);
    reverse(z, z + n);
    for (int i = 0; i < n; i++)
    {
        perm[z[i].second] = i;
        cost[i] = z[i].first;
    }
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[perm[x]].push_back(perm[y]);
        g[perm[y]].push_back(perm[x]);
    }
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1LL;
    }

    for (int v = 0; v < n; v++)
    {
        used[v] = 1;
        for (int i = 0; i < g[v].size(); i++)
        {
            int to = g[v][i];
            if (used[to])
            {
                int p1 = get_par(v);
                int p2 = get_par(to);
                if (p1 != p2)
                {
                    ans += cost[v] * sz[p1] * sz[p2];
                    my_union(p1, p2);
                }
            }
        }
    }
    double tmp = 2. * (double)ans / (double)(n - 1) / (double)n;
    printf("%.6lf\n", tmp);
    return 0;
}