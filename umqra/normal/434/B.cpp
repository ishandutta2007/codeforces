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
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define X first
#define Y second
#define mp make_pair

const int N = (int)1e3 + 100;

int a[N][N];
int rightC[N][N], upC[N][N], leftC[N][N], downC[N][N];

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);    
    for (int i = 0; i < n; i++)
        for (int s = 0; s < m; s++)
            scanf("%d", &a[i][s]);

    for (int y = 0; y < m; y++)
    for (int s = 0; s < n; s++)
    {
        upC[s][y] = (s == 0 ? 0 : upC[s - 1][y]);
        if (a[s][y])
            upC[s][y]++;
        else
            upC[s][y] = 0;
    }
    for (int y = 0; y < m; y++)
    for (int s = n - 1; s >= 0; s--)
    {
        downC[s][y] = (s == n - 1 ? 0 : downC[s + 1][y]);
        if (a[s][y])
            downC[s][y]++;
        else
            downC[s][y] = 0;
    }
    for (int x = 0; x < n; x++)
    for (int s = 0; s < m; s++)
    {
        leftC[x][s] = (s == 0 ? 0 : leftC[x][s - 1]);
        if (a[x][s])
            leftC[x][s]++;
        else
            leftC[x][s] = 0;
    }
    for (int x = 0; x < n; x++)
    for (int s = m - 1; s >= 0; s--)
    {
        rightC[x][s] = (s == m - 1 ? 0 : rightC[x][s + 1]);
        if (a[x][s])
            rightC[x][s]++;
        else
            rightC[x][s] = 0;
    }


    for (int i = 0; i < q; i++)
    {
        int op;
        int x, y;
        scanf("%d%d%d", &op, &x, &y);
        x--, y--;
        if (op == 1)
        {
            a[x][y] ^= 1;
            for (int s = 0; s < n; s++)
            {
                upC[s][y] = (s == 0 ? 0 : upC[s - 1][y]);
                if (a[s][y])
                    upC[s][y]++;
                else
                    upC[s][y] = 0;
            }
            for (int s = n - 1; s >= 0; s--)
            {
                downC[s][y] = (s == n - 1 ? 0 : downC[s + 1][y]);
                if (a[s][y])
                    downC[s][y]++;
                else
                    downC[s][y] = 0;
            }
            for (int s = 0; s < m; s++)
            {
                leftC[x][s] = (s == 0 ? 0 : leftC[x][s - 1]);
                if (a[x][s])
                    leftC[x][s]++;
                else
                    leftC[x][s] = 0;
            }
            for (int s = m - 1; s >= 0; s--)
            {
                rightC[x][s] = (s == m - 1 ? 0 : rightC[x][s + 1]);
                if (a[x][s])
                    rightC[x][s]++;
                else
                    rightC[x][s] = 0;
            }
        }
        else
        {
            int ans = 0;
            int l = y - leftC[x][y] + 1;
            int r = y + rightC[x][y] - 1; 
            for (int s = x; s < n; s++)
            {
                int cl = y - leftC[s][y] + 1;
                int cr = y + rightC[s][y] - 1;
                l = max(l, cl);
                r = min(r, cr);
                ans = max(ans, (s - x + 1) * max(0, r - l + 1));
            }
            l = y - leftC[x][y] + 1;
            r = y + rightC[x][y] - 1; 
            for (int s = x; s >= 0; s--)
            {
                int cl = y - leftC[s][y] + 1;
                int cr = y + rightC[s][y] - 1;
                l = max(l, cl);
                r = min(r, cr);
                ans = max(ans, (x - s + 1) * max(0, r - l + 1));        
            }                   

            l = x - upC[x][y] + 1;
            r = x + downC[x][y] - 1;
            for (int s = y; s < m; s++)
            {
                int cl = x - upC[x][s] + 1;
                int cr = x + downC[x][s] - 1;
                l = max(cl, l);
                r = min(r, cr);
                ans = max(ans, (s - y + 1) * max(0, r - l + 1));
            }
            l = x - upC[x][y] + 1;
            r = x + downC[x][y] - 1;
            for (int s = y; s >= 0; s--)
            {
                int cl = x - upC[x][s] + 1;
                int cr = x + downC[x][s] - 1;
                l = max(cl, l);
                    r = min(r, cr);
                ans = max(ans, (y - s + 1) * max(0, r - l + 1));
            }


            printf("%d\n", ans);
        }
    }

    return 0;
}