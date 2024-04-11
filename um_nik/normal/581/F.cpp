#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int INF = (int)1e6;
const int N = 5020;
int n;
int dp[N][2][N];
int sz[N];
vector<int> g[N];
bool used[N];

void read()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    return;
}

void dfs(int v)
{
    used[v] = 1;
    if ((int)g[v].size() == 1)
    {
        sz[v] = 1;
        dp[v][0][1] = 0;
        dp[v][1][0] = 0;
        return;
    }
    int d[2][2][N];
    d[0][0][0] = 0;
    d[1][0][0] = 0;
    sz[v] = 0;
    for (int u : g[v])
    {
        if (used[u]) continue;
        dfs(u);
        for (int c = 0; c < 2; c++)
        {
            for (int i = 0; i <= sz[v] + sz[u]; i++)
                d[c][1][i] = INF;
            for (int i = 0; i <= sz[v]; i++)
                for (int j = 0; j <= sz[u]; j++)
                    for (int col = 0; col < 2; col++)
                        if (d[c][0][i] != INF && dp[u][col][j] != INF)
                            d[c][1][i + j] = min(d[c][1][i + j], d[c][0][i] + dp[u][col][j] + (c ^ col));
            for (int i = 0; i <= sz[v] + sz[u]; i++)
                d[c][0][i] = d[c][1][i];
        }
        sz[v] += sz[u];
    }
    for (int c = 0; c < 2; c++)
        for (int i = 0; i <= sz[v]; i++)
            dp[v][c][i] = d[c][0][i];
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    if (n == 2)
    {
        printf("1\n");
        return 0;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            for (int k = 0; k <= n; k++)
                dp[i][j][k] = INF;
    int v = 0;
    while((int)g[v].size() == 1) v++;
    dfs(v);
    if (sz[v] & 1) throw;
    int ans = min(dp[v][0][sz[v] / 2], dp[v][1][sz[v] / 2]);
    printf("%d\n", ans);

    return 0;
}