#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge
{
    int to, nxt;
} e[200001];
int n, E, head[200001], a[200001], sz[200001];
long long sum[200001], ans;
void checkmax(long long &x, long long y)
{
    if (x < y)
    {
        x = y;
    }
}
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void dfs(int u)
{
    sum[u] = a[u];
    sz[u] = head[u] == -1;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        dfs(v);
        sz[u] += sz[v];
        sum[u] += sum[v];
    }
    checkmax(ans, (sum[u] + sz[u] - 1) / sz[u]);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(head, -1, sizeof(head));
    cin >> n;
    int fa;
    for (int i = 2; i <= n; i++)
    {
        cin >> fa;
        add(fa, i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dfs(1);
    cout << ans;
    return 0;
}