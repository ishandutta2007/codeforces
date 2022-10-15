#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const long long MOD = 1e9 + 7;
struct edge
{
    int to, nxt;
    edge(int to = 0, int nxt = -1) : to(to), nxt(nxt) {}
} e[200001];
int n, E, head[100001];
long long a[100001], ans;
map<long long, int> mp[100001];
void add(int f, int t)
{
    e[E].to = t;
    e[E].nxt = head[f];
    head[f] = E++;
}
void dfs(int u, int fa)
{
    for (auto i : mp[fa])
    {
        long long t = __gcd(i.first, a[u]);
        mp[u][t] += i.second;
        ans = (ans + t * i.second % MOD) % MOD;
    }
    mp[u][a[u]]++;
    ans = (ans + a[u]) % MOD;
    for (int i = head[u]; i != -1; i = e[i].nxt)
    {
        int v = e[i].to;
        if (v == fa)
        {
            continue;
        }
        dfs(v, u);
    }
}
int main(int argc, char const *argv[])
{
    memset(head, -1, sizeof(head));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &a[i]);
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    dfs(1, 0);
    printf("%lld", ans);
    return 0;
}