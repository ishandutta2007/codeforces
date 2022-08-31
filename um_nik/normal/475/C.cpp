#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
using namespace std;

const int INF = (int)1e9;
int n, m;
int w, h;
string s;
bool g[1010][1010];
int a[1010][1010];
int b[1010][1010];
int ans = INF;
int stX = -1, stY = -1;
int black;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
            if (s[j] == 'X')
                g[i][j] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            black += (int)g[i][j];
    for (int j = 0; j < m; j++)
        for (int i = n - 1; i >= 0; i--)
            if (g[i][j])
                a[i][j] = a[i + 1][j] + 1;
            else
                a[i][j] = 0;
    for (int i = 0; i < n; i++)
        for (int j = m - 1; j >= 0; j--)
            if (g[i][j])
                b[i][j] = b[i][j + 1] + 1;
            else
                b[i][j] = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < m; j++)
        {
            if (!(g[i][j] && g[i + 1][j]))
                continue;
            if (b[i][j] > b[i + 1][j])
            {
                printf("-1\n");
                return 0;
            }
        }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            if (g[i][j])
            {
                stX = i;
                stY = j;
                break;
            }
        if (stX != -1)
            break;
    }
    for (int h = 1; h <= n; h++)
    {
        int x = stX, y = stY;
        if (h > a[x][y])
            break;
        w = 0;
        bool good = 1;
        int d = 0, r = 0;
        while(a[x][y] > h || b[x][y] > max(w, 1))
        {
            if (a[x][y] > h)
            {
                if (w != 0 && w != b[x][y])
                {
                    good = 0;
                    break;
                }
                w = b[x][y];
                x++;
                d++;
            }
            else
            {
                y++;
                r++;
            }
        }
        if (!good)
            continue;
        if (w == 0) w = 1;
        int sq = h * w + r * h + d * w;
        if (sq != black)
            continue;
        ans = min(ans, w * h);
    }
    if (ans == INF)
        printf("-1\n");
    else
        printf("%d\n", ans);

    return 0;
}