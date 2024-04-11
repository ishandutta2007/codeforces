#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n, m, q;
string s;
int a[50][50], b[50][50], c[50][50][50][50];

int main()
{
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            a[i][j + 1] = (int)s[j] - 48;
            b[i][j + 1] = b[i - 1][j + 1] + b[i][j] - b[i - 1][j] + a[i][j + 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            for (int h = i; h <= n; h++)
            {
                for (int k = j; k <= m; k++)
                {
                    if (b[h][k] - b[i - 1][k] - b[h][j - 1] + b[i - 1][j - 1] == 0)
                        c[i][j][h - i + 1][k - j + 1]++;
                    c[i][j][h - i + 1][k - j + 1] += c[i][j][h - i][k - j + 1] + c[i][j][h - i + 1][k - j] - c[i][j][h - i][k - j];
                }
            }
        }
    }
    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        int ans = 0;
        for (int i = x1; i <= x2; i++)
        {
            for (int j = y1; j <= y2; j++)
            {
                ans += c[i][j][x2 - i + 1][y2 - j + 1];
            }
        }
        printf("%d\n", ans);
    }
    //cin >> n;
    return 0;
}