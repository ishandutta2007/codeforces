#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

const ll MOD = (ll)1e9 + 7;
ll add(ll x, ll y)
{
    x += y;
    if (x >= MOD) return x - MOD;
    return x;
}
ll sub(ll x, ll y)
{
    x -= y;
    if (x < 0) return x + MOD;
    return x;
}
ll mult(ll x, ll y)
{
    return (x * y) % MOD;
}
ll bin_pow(ll x, ll p)
{
    if (p == 0) return 1;
    if (p & 1) return mult(x, bin_pow(x, p - 1));
    return bin_pow(mult(x, x), p / 2);
}
ll rev(ll x)
{
    return bin_pow(x, MOD - 2);
}

const int N = 100100;
int n;
vector<pii> g[N];
ll a[N][2];

void dfs(int v, int par)
{
    if ((int)g[v].size() == 1)
    {
        a[v][0] = a[v][1] = 0;
        return;
    }
    ll p = (int)g[v].size();
    ll q = 0;
    for (pii e : g[v])
        q = add(q, e.second);
    for (pii e : g[v])
    {
        int u = e.first;
        if (u == par) continue;
        dfs(u, v);
        p = sub(p, a[u][0]);
        q = add(q, a[u][1]);
    }
    if (p == 0) throw;
    p = rev(p);
    a[v][0] = p;
    a[v][1] = mult(q, p);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        g[v].push_back(mp(u, w));
        g[u].push_back(mp(v, w));
    }
    for (pii e : g[0])
        dfs(e.first, 0);

    ll p = (int)g[0].size();
    ll q = 0;
    for (pii e : g[0])
        q = add(q, e.second);
    for (pii e : g[0])
    {
        int u = e.first;
        p = sub(p, a[u][0]);
        q = add(q, a[u][1]);
    }
    if (p == 0) throw;
    printf("%lld\n", mult(q, rev(p)));

    return 0;
}