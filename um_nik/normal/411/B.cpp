#include <iostream>
using namespace std;

int n, m, k;
int ans[200];
int q[200][200];
int a[200];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &q[j][i]);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[j] > 0 || q[i][j] == 0)
                continue;
            if (a[ q[i][j] ] != 0)
            {
                ans[j] = i;
    //          printf("!!!\n");
                continue;
            }
            for (int s = 0; s < n; s++)
            {
                if (ans[s] > 0 || j == s)
                    continue;
                if (q[i][j] == q[i][s])
                {
                    //printf("%d %d %d\n", i, j, s);
                    ans[j] = i;
                    ans[s] = i;
                    a[ q[i][j] ] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d\n", ans[i]);
//  cin >> n;
    return 0;
}