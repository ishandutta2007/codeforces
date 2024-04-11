#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
int n, m, q, a[1003][1003], up[1001][1001], down[1001][1001], left[1001][1001], right[1001][1001], L, R, ans, op, x, y;
void renewrow(int row)
{
    for(int i = 1; i <= m; i++)
        if(a[row][i])
            left[row][i] = a[row][i - 1]?left[row][i - 1] + 1:1;
    for(int i = m; i >= 1; i--)
        if(a[row][i])
            right[row][i] = a[row][i + 1]?right[row][i + 1] + 1:1;
}
void renewcol(int col)
{
    for(int i = 1; i <= n; i++)
        if(a[i][col])
            up[i][col] = a[i - 1][col]?up[i - 1][col] + 1:1;
    for(int i = n; i >= 1; i--)
        if(a[i][col])
            down[i][col] = a[i + 1][col]?down[i + 1][col] + 1:1;
}
int main()
{
    scanf("%d%d%d", &n, &m, &q);
    memset(a, 0, sizeof(a));
    for(int i = 1; i <= n; i++) for(int j = 1; j  <= m; j++) scanf("%d", &a[i][j]);
    for(int i = 1; i <= n; i++) renewrow(i);
    for(int j = 1; j <= m; j++) renewcol(j);
    for(int qq = 1; qq <= q; qq++)
    {
        scanf("%d%d%d", &op, &x, &y);
        if(op == 1)
        {
            a[x][y] ^= 1;
            renewrow(x);
            renewcol(y);
        }else
        {
            ans = 0;
            L = 0x7fffffff;
            R = 0x7fffffff;
            for(int i = x; i <= n and a[i][y]; i++)
            {
                L = min(L, left[i][y]);
                R = min(R, right[i][y]);
                ans = max(ans, (L + R - 1) * (i - x + 1));
            }
            L = 0x7fffffff;
            R = 0x7fffffff;
            for(int i = x; i >= 1 and a[i][y]; i--)
            {
                L = min(L, left[i][y]);
                R = min(R, right[i][y]);
                ans = max(ans, (L + R - 1) * (x - i + 1));
            }
            L = 0x7fffffff;
            R = 0x7fffffff;
            for(int i = y; i <= m and a[x][i]; i++)
            {
                L = min(L, up[x][i]);
                R = min(R, down[x][i]);
                ans = max(ans, (L + R - 1) * (i - y + 1));
            }
            L = 0x7fffffff;
            R = 0x7fffffff;
            for(int i = y; i >= 1 and a[x][i]; i--)
            {
                L = min(L, up[x][i]);
                R = min(R, down[x][i]);
                ans = max(ans, (L + R - 1) * (y - i + 1));
            }
            printf("%d\n", ans);
        }
    }
    fclose(stdin);
    return 0;
}