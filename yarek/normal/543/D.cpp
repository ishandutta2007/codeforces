#include <cstdio>
#include <vector>
using namespace std;

long long dp1[200001];
long long dp2[200001];
vector<int> g[200001];
const long long mod = 1000000007;

long long pow(long long a, int k)
{
    if(k == 0) return 1;
    if(k % 2) return pow(a, k - 1) * a % mod;
    return pow(a * a % mod, k / 2);
}

inline long long inv(long long a)
{
    return pow(a, mod - 2);
}

void dfs1(int v, int prev)
{
    dp1[v] = 1;
    for(int u: g[v])
    if(u != prev)
    {
        dfs1(u, v);
        dp1[v] = dp1[v] * (dp1[u] + 1) % mod;
    }
}

void dfs2(int v, int prev)
{
    dp2[v] = (dp2[v] + 1) % mod;
    vector<long long> ilo1(g[v].size() + 1), ilo2(g[v].size() + 1);
    ilo1[0] = 1;
    ilo2.back() = 1;
    for(int i = 0; i < g[v].size(); i++)
    {
    int u = g[v][i];
    if(u != prev)
        ilo1[i+1] = ilo1[i] * (dp1[u] + 1) % mod;
    else ilo1[i+1] = ilo1[i];
    }
    for(int i = g[v].size() - 1; i >= 0; i--)
    {
    int u = g[v][i];
    if(u != prev)
        ilo2[i] = ilo2[i+1] * (dp1[u] + 1) % mod;
    else ilo2[i] = ilo2[i+1];
    }
    for(int i = 0; i < g[v].size(); i++)
    {
    int u = g[v][i];
    if(u != prev)
    {
        dp2[u] = dp2[v] * ilo1[i] % mod * ilo2[i+1] % mod;
        dfs2(u, v);
    }
    }
}

int main()
{
    int n, a, b;
    scanf("%d", &n);
    for(int i = 2; i <= n; i++)
    {
    scanf("%d", &a);
    b = i;
    g[a].push_back(b);
    g[b].push_back(a);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    for(int i = 1; i <= n; i++)
    printf("%d ", (int)(dp1[i] * dp2[i] % mod));
    puts("");
}