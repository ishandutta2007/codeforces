#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;
#define mp make_pair
#define X first
#define Y second

const int N = 100100;
int par[N], sz[N];
ll ans[N];
pli a[N];
int l[N], r[N];
int q, n;

int getPar(int v)
{
    return (par[v] == -1 ? v : par[v] = getPar(par[v]));
}
void unite(int v, int u)
{
    v = getPar(v);
    u = getPar(u);
    if (v == u) return;
    if (sz[v] < sz[u]) swap(v, u);
    sz[v] += sz[u];
    par[u] = v;
    return;
}

void read()
{
    scanf("%d%d", &n, &q);
    ll x;
    for (int i = 0; i < n; i++)
    {
        par[i] = -1;
        sz[i] = 1;
    }
    scanf("%lld", &x);
    for (int i = 0; i < n - 1; i++)
    {
        ll y;
        scanf("%lld", &y);
        a[i] = mp(abs(x - y), i);
        x = y;
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d%d", &l[i], &r[i]);
        l[i]--;r[i]--;
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    n--;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int p = a[i].Y;
        ll L = sz[getPar(p)], R = sz[getPar(p + 1)];
//      printf("%d %lld %lld\n", p, L, R);
        unite(p, p + 1);
        for (int j = 0; j < q; j++)
            if (l[j] <= p && p < r[j])
                ans[j] += a[i].X * min((ll)p - l[j] + 1, L) * min((ll)r[j] - p, R);
    }
    for (int i = 0; i < q; i++)
        printf("%lld\n", ans[i]);

    return 0;
}