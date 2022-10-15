#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m, a[101][101], p[1000001], ans[1000001], tot, dis[101][101];
vector<int> b[101][101];
bool vis[1000001];
int main(int argc, char const *argv[])
{
    memset(dis, 127 / 3, sizeof(dis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%1d", &a[i][j]);
            if (a[i][j])
            {
                dis[i][j] = 1;
            }
        }
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &p[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i][i] = 0;
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                    b[i][j].clear();
                    b[i][j].push_back(k);
                }
                if (dis[i][j] == dis[i][k] + dis[k][j])
                {
                    b[i][j].push_back(k);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i])
        {
            ans[++tot] = p[i];
            int j = i + 2;
            while (j <= m)
            {
                bool f = 0;
                for (int k = 0, sz = (int)b[p[i]][p[j]].size(); k < sz; k++)
                {
                    if (b[p[i]][p[j]][k] == p[j - 1])
                    {
                        f = 1;
                        break;
                    }
                }
                if (!f)
                {
                    break;
                }
                vis[j - 1] = 1;
                j++;
            }
        }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}