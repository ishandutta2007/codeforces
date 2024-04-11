#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define X first
#define Y second
#define mp make_pair

const int N = (int)1e5 + 100;

vector <int> g[N];

int h[N];
bool used[N];
int up[N];
int k;

void printPath(int a, int b)
{
    while (a != b)
    {
        printf("%d ", a);
        a = up[a];
    }
    printf("%d", b);
    exit(0);
}

void dfs(int v)
{
    used[v] = 1;
    bool f = false;
    for (int i = 0; i < (int)g[v].size(); i++)
    {
        int to = g[v][i];
        if (!used[to])
        {
            h[to] = h[v] + 1;
            up[to] = v;
            dfs(to);   
            f = true;
        }
    }
    if (!f)
    {
        for (int i = 0; i < (int)g[v].size(); i++)
        {
            int to = g[v][i];
            if (h[v] - h[to] >= k)
            {
                printf("%d\n", h[v] - h[to] + 1);
                printPath(v, to);
            }
        }   
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n;
    int m;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1);

    return 0;
}