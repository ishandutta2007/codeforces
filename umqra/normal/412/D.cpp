#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;

const int N = (int)1e5;
vector <int> g[N];
int ans[N];
bool used[N];
int indAns = 0;

void dfs(int v)
{
    used[v] = 1;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (!used[to])
            dfs(to);
    }
    ans[indAns++] = v;
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!used[i])
            dfs(i);
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);

    return 0;
}