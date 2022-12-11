#include <bits/stdc++.h>
using namespace std;

int sum[11][105][105];

int main()
{
    int n, q, c;
    scanf("%d%d%d",&n,&q,&c);
    for (int i = 0; i < n; i++)
    {
        int x, y, s;
        scanf("%d%d%d",&x,&y,&s);
        for (int j = 0; j <= c; j++)
        {
            sum[j][x][y] += (s + j) % (c + 1);
        }
    }

    for (int i = 0; i <= c; i++)
    {
        auto &sum = ::sum[i];
        for (int j = 1; j <= 100; j++)
        {
            for (int k = 1; k <= 100; k++)
            {
                sum[j][k] += sum[j-1][k] + sum[j][k-1] - sum[j-1][k-1];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        int t, a, b, x, y;
        scanf("%d%d%d%d%d",&t,&a,&b,&x,&y);
        auto &s = sum[t % (c + 1)];
        printf("%d\n",
            s[x][y] - s[a-1][y] - s[x][b-1] + s[a-1][b-1]
        );
    }
}