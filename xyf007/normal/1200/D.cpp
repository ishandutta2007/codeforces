#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, k, ans[2001][2001];
char a[2001][2001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", a[i] + 1);
    }
    int maxx = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = -1, r = -1, lm, rm, um, dm;
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 'B')
            {
                l = j;
                break;
            }
        }
        for (int j = n; j >= 1; j--)
        {
            if (a[i][j] == 'B')
            {
                r = j;
                break;
            }
        }
        if (l == -1 && r == -1)
        {
            maxx++;
            continue;
        }
        if (r - l + 1 > k)
        {
            continue;
        }
        lm = max(r - k + 1, 1);
        rm = l;
        um = max(i - k + 1, 1);
        dm = i;
        ans[um][lm]++;
        ans[min(dm + 1, n + 1)][lm]--;
        ans[um][min(rm + 1, n + 1)]--;
        ans[min(dm + 1, n + 1)][min(rm + 1, n + 1)]++;
    }
    for (int i = 1; i <= n; i++)
    {
        int u = -1, d = -1, lm, rm, um, dm;
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] == 'B')
            {
                u = j;
                break;
            }
        }
        for (int j = n; j >= 1; j--)
        {
            if (a[j][i] == 'B')
            {
                d = j;
                break;
            }
        }
        if (u == -1 && d == -1)
        {
            maxx++;
            continue;
        }
        if (d - u + 1 > k)
        {
            continue;
        }
        lm = max(i - k + 1, 1);
        rm = i;
        um = max(d - k + 1, 1);
        dm = u;
        ans[um][lm]++;
        ans[min(dm + 1, n + 1)][lm]--;
        ans[um][min(rm + 1, n + 1)]--;
        ans[min(dm + 1, n + 1)][min(rm + 1, n + 1)]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans[j][i] += ans[j - 1][i];
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ans[i][j] += ans[i][j - 1];
            checkmax(sum, ans[i][j]);
        }
    }
    printf("%d", maxx + sum);
    return 0;
}