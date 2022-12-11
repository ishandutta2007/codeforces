#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
using namespace std;

const int INF = (int)1e9;
typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e3 + 10;
int g[N][N];
int ans;
vector <int> edge[N];
char table[N][11][11];
bool used[N];
int par[N];
int n, m, k;
int d[N];

int calcDiff(int a, int b)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
            ans += (table[a][i][s] != table[b][i][s]);
    return ans;
}

void findMST()
{
    fill(d, d + N, INF);
    d[k] = 0;
    par[k] = -1;
    ans = 0;
    while (1)
    {
        int bst = INF, ind = -1;
        for (int i = 0; i <= k; i++)
        {
            if (d[i] < bst && !used[i])
            {
                bst = d[i];
                ind = i;
            }
        }
        if (bst == INF)
            break;
        ans += bst;
        used[ind] = 1;
        for (int i = 0; i <= k; i++)
        {
            if (!used[i] && d[i] > g[ind][i])
            {
                par[i] = ind;
                d[i] = g[ind][i];
            }
        }
    }
}

void dfs(int v)
{
    for (int i = 0; i < (int)edge[v].size(); i++)
    {
        int to = edge[v][i];
        if (v == k)
        {
            printf("%d %d\n", to + 1, 0);
            dfs(to);
        }
        else
        {
            printf("%d %d\n", to + 1, v + 1);
            dfs(to);
        }
    }
}

int main()
{
    int w;
    scanf("%d%d%d%d", &n, &m, &k, &w);
    
    for (int i = 0; i < k; i++)
        for (int s = 0; s < n; s++)
            scanf(" %s", table[i][s]);
        
    for (int i = 0; i < k; i++)
        for (int s = 0; s < i; s++)
        {
            g[i][s] = g[s][i] = calcDiff(i, s) * w;
        }
    for (int i = 0; i < k; i++)
        g[i][k] = g[k][i] = n * m;
    
    findMST();
    for (int i = 0; i <= k; i++)
        if (par[i] != -1)
            edge[par[i]].push_back(i);
    printf("%d\n", ans);
    dfs(k);
    
    return 0;
}