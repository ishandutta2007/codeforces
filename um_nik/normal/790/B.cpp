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

const int N = 200200;
const int K = 6;
int n, k;
vector<int> g[N];
int a[N][K];
int sz[N];
ll ans = 0;
bool used[N];
int b[K];

void dfs1(int v)
{
    used[v] = 1;
    a[v][0] = 1;
    sz[v] = 1;
    for (int u : g[v])
    {
        if (used[u]) continue;
        dfs1(u);
        ans += (ll)a[u][0] * (ll)(n - sz[u]);
        for (int i = 0; i < k; i++)
            a[v][(i + 1) % k] += a[u][i];
        sz[v] += sz[u];
    }
    return;
}

void dfs2(int v)
{
    for (int i = k - 2; i >= 0; i--)
        swap(b[i], b[i + 1]);
    for (int i = 0; i < k; i++)
        b[i] += a[v][i];
    for (int u : g[v])
    {
        if (sz[u] >= sz[v]) continue;
        for (int i = 0; i < k; i++)
            b[(i + 1) % k] -= a[u][i];
        ans += (ll)b[0] * (ll)sz[u];
        dfs2(u);
        for (int i = 0; i < k; i++)
            b[(i + 1) % k] += a[u][i];
    }
    for (int i = 0; i < k; i++)
        b[i] -= a[v][i];
    for (int i = 0; i < k - 1; i++)
        swap(b[i], b[i + 1]);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs1(0);
    dfs2(0);
    printf("%lld\n", ans / 2);

    return 0;
}