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

const int N = 100100;
const int LOG = 18;
vector<int> g[N];
int par[N][LOG];
int h[N];
int n;

void dfs(int v)
{
    for (int u : g[v]) {
        if (h[u] != -1) continue;
        h[u] = h[v] + 1;
        par[u][0] = v;
        for (int k = 0; k < LOG - 1; k++) {
            if (par[u][k] == -1) break;
            par[u][k + 1] = par[par[u][k]][k];
        }
        dfs(u);
    }
}

int up(int v, int dh)
{
    for (int k = LOG - 1; k >= 0; k--) {
        if (dh < (1 << k)) continue;
        dh -= 1 << k;
        v = par[v][k];
    }
    return v;
}
int LCA(int v, int u)
{
    if (h[v] > h[u]) swap(v, u);
    u = up(u, h[u] - h[v]);
    if (v == u) return v;
    for (int k = LOG - 1; k >= 0; k--) {
        if (par[v][k] != par[u][k]) {
            v = par[v][k];
            u = par[u][k];
        }
    }
    return par[v][0];
}
int getDist(int v, int u)
{
    int w = LCA(v, u);
    return h[v] + h[u] - 2 * h[w];
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int q;
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; i++) {
        int v;
        scanf("%d", &v);
        v--;
        g[v].push_back(i);
        g[i].push_back(v);
    }
    for (int i = 0; i < n; i++) {
        h[i] = -1;
        for (int j = 0; j < LOG; j++)
            par[i][j] = -1;
    }
    h[0] = 0;
    dfs(0);

    while(q--) {
        int v, u, w;
        scanf("%d%d%d", &v, &u, &w);
        v--;u--;w--;
        int a = getDist(v, u), b = getDist(v, w), c = getDist(u, w);
        printf("%d\n", 1 + (a + b + c) / 2 - min(a, min(b, c)));
    }

    return 0;
}