#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct edge
{
    int u, v, c;
    bool operator<(const edge a) const
    {
        return c > a.c;
    }
} e[500001];
int n, m, a[100001], b[100001], fa[200001], E;
int find(int x)
{
    if (x == fa[x])
    {
        return x;
    }
    return fa[x] = find(fa[x]);
}
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n + m; i++)
    {
        fa[i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int s, x;
        cin >> s;
        for (int j = 1; j <= s; j++)
        {
            cin >> x;
            e[++E] = (edge){i, x + n, a[i] + b[x]};
            ans += a[i] + b[x];
        }
    }
    sort(e + 1, e + E + 1);
    for (int i = 1; i <= E; i++)
    {
        int fx = find(e[i].u), fy = find(e[i].v);
        if (fx == fy)
        {
            continue;
        }
        fa[fx] = fy;
        ans -= e[i].c;
    }
    cout << ans;
    return 0;
}