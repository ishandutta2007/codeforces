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
int n, k;
vector<int> g[N];
int col[N];

void dfs(int v, int par)
{
    int t = 0;
    for (int u : g[v])
    {
        if (u == par) continue;
        while(t == col[v] || t == col[par]) t++;
        col[u] = t;
        dfs(u, v);
        t++;
    }
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    k = 1;
    for (int i = 0; i < n; i++)
        k = max(k, (int)g[i].size() + 1);
    for (int i = 0; i < n; i++)
        col[i] = -1;
    col[0] = 0;
    int t = 1;
    for (int v : g[0])
    {
        col[v] = t++;
        dfs(v, 0);
    }
    printf("%d\n", k);
    for (int i = 0; i < n; i++)
        printf("%d ", col[i] + 1);
    printf("\n");

    return 0;
}