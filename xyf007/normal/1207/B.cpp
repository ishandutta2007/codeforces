#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n, m, a[51][51], b[51][51], sum;
vector<pair<int, int>> ans;
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][j] && a[i + 1][j] && a[i][j + 1] && a[i + 1][j + 1])
            {
                b[i][j] = b[i + 1][j] = b[i][j + 1] = b[i + 1][j + 1] = 1;
                sum++;
                ans.push_back(make_pair(i, j));
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != b[i][j])
            {
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d\n", sum);
    for (int i = 0; i < sum; i++)
    {
        printf("%d %d\n", ans[i].first, ans[i].second);
    }
    return 0;
}