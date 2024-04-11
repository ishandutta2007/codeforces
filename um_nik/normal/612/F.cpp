#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = (int)1e8 + 10;
const int N = 2020;
int n, m, s;
int a[N];
int c[N];
vector<int> b[N];
int dp[N][2];
int par[N][2];
int ans[N];

void read()
{
    scanf("%d%d", &n, &s);
    s--;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    sort(c, c + n);
    m = unique(c, c + n) - c;
    for (int i = 0; i < n; i++)
    {
        a[i] = lower_bound(c, c + m, a[i]) - c;
        b[a[i]].push_back(i);
    }
    return;
}

int getDist(int x, int y)
{
    int d = (n + y - x) % n;
    if (d > n - d)
        d -= n;
    return d;
}

void restore(int v)
{
    int idx = n;
    for (int val = m - 1; val >= 0; val--)
    {
        ans[idx--] = v;

        if ((int)b[val].size() > 1)
        {
            int u = par[v][1];
            int it = 0;
            while(b[val][it] != v) it++;
            if (b[val][(it + 1) % (int)b[val].size()] == u)
            {
                while(b[val][it] != u)
                {
                    it = (it + (int)b[val].size() - 1) % (int)b[val].size();
                    ans[idx--] = b[val][it];
                }
            }
            else
            {
                while(b[val][it] != u)
                {
                    it = (it + 1) % (int)b[val].size();
                    ans[idx--] = b[val][it];
                }
            }
            v = u;
        }

        if (val == 0) break;

        v = par[v][0];
    }
    ans[0] = s;
    for (int i = 0; i < n; i++)
    {
        int x = getDist(ans[i], ans[i + 1]);
        if (x >= 0)
            printf("+%d\n", x);
        else
            printf("%d\n", x);
    }
    return;
}

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    read();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            dp[i][j] = INF;
    for (int x : b[0])
        dp[x][0] = abs(getDist(s, x));
    for (int val = 0; val < m; val++)
    {
        if (b[val].size() == 1)
        {
            for (int x : b[val])
            {
                dp[x][1] = dp[x][0];
                par[x][1] = x;
            }
        }
        else
        {
            for (int i = 0; i < (int)b[val].size(); i++)
            {
                for (int dx = -1; dx <= 1; dx += 2)
                {
                    int nxt = (i + dx + (int)b[val].size()) % (int)b[val].size();
                    int dist = getDist(b[val][i], b[val][nxt]);
                    if (dx < 0 && dist < 0)
                        dist += n;
                    if (dx > 0 && dist > 0)
                        dist -= n;
                    int w = dp[b[val][i]][0] + abs(dist);
                    if (w < dp[b[val][nxt]][1])
                    {
                        dp[b[val][nxt]][1] = w;
                        par[b[val][nxt]][1] = b[val][i];
                    }
                }
            }
        }

        if (val == m - 1) break;

        for (int x : b[val])
            for (int y : b[val + 1])
            {
                int w = dp[x][1] + abs(getDist(x, y));
                if (w < dp[y][0])
                {
                    dp[y][0] = w;
                    par[y][0] = x;
                }
            }
    }

    int v = b[m - 1][0];
    for (int u : b[m - 1])
        if (dp[u][1] < dp[v][1])
            v = u;
    printf("%d\n", dp[v][1]);
    restore(v);

    return 0;
}