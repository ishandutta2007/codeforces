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

const int N = 300300;
vector<int> g[N];
int col[N];
bool used[N];
vector<int> a[N];
bool b[N];
int n, m;

void dfs(int v)
{
    used[v] = 1;
    for (int c : a[v])
    {
        if (col[c] == -1) continue;
        b[col[c]] = 1;
    }
    int p = 0;
    for (int c : a[v])
    {
        if (col[c] != -1) continue;
        while(b[p]) p++;
        col[c] = p;
        b[p] = 1;
    }
    for (int c : a[v])
        b[col[c]] = 0;
    for (int u : g[v])
        if (!used[u])
            dfs(u);
    return;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        a[i].resize(k);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }
    for (int j = 0; j < m; j++)
        col[j] = -1;
    for (int i = 1; i < n; i++)
    {
        int v, u;
        scanf("%d%d", &v, &u);
        v--;u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0);
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (col[i] == -1)
            col[i] = 0;
        ans = max(ans, col[i] + 1);
    }
    printf("%d\n", ans);
    for (int i = 0; i < m; i++)
        printf("%d ", col[i] + 1);
    printf("\n");

    return 0;
}