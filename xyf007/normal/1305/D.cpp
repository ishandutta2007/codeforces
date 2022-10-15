#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, ind[1001];
queue<int> leaf;
bool g[1001][1001];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u][v] = g[v][u] = 1;
        ind[u]++;
        ind[v]++;
    }
    for (int i = 1; i <= n; i++)
    {
        if (ind[i] == 1)
        {
            leaf.push(i);
        }
    }
    while (leaf.size() > 1)
    {
        int u = leaf.front(), v, LCA;
        leaf.pop();
        v = leaf.front();
        leaf.pop();
        printf("? %d %d\n", u, v);
        fflush(stdout);
        scanf("%d", &LCA);
        if (LCA == u || LCA == v)
        {
            printf("! %d", LCA);
            fflush(stdout);
            return 0;
        }
        for (int i = 1; i <= n; i++)
        {
            if (g[u][i])
            {
                g[u][i] = 0;
                if (--ind[i] == 1)
                {
                    leaf.push(i);
                }
            }
            if (g[v][i])
            {
                g[v][i] = 0;
                if (--ind[i] == 1)
                {
                    leaf.push(i);
                }
            }
        }
    }
    printf("! %d", leaf.front());
    fflush(stdout);
    return 0;
}