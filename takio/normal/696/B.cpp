#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int N = 100100;

vector <int> g[N];
double res[N];
int sz[N];

void dfs (int u) {
//    cout <<u << endl;
    sz[u] = 1;
    for (int i = 0; i < g[u].size(); i++) {
        dfs (g[u][i]);
        sz[u] += sz[g[u][i]];
    }
}

void dfs2 (int u) {
//    sz[u] = 1;
    int sum = 0;
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        sum += sz[v];
    }
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        res[v] = res[u] + 1.0 * (sum - sz[v]) / 2 + 1;
    }
    for (int i = 0; i < g[u].size(); i++) {
        dfs2 (g[u][i]);
    }
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, x;
    cin >> n;
    for (int i = 1; i < n; i++) {
        scanf ("%d", &x);
        g[x].push_back (i + 1);
    }
    res[1] = 1.0;
    dfs (1);
    dfs2 (1);
    for (int i = 1; i <= n; i++) {
        printf ("%.10f ", res[i]);
    }
//    for (int i = 0; i < g[1].size(); i++)  {
//        dfs (g[1][i], 1);
//    }
//    dfs (1);
}