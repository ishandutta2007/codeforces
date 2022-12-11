#include <bits/stdc++.h>
using namespace std;

int a[105][105];
int b[105][105];
int sum[105];

vector<pair<string, int>> ans;
string row = "row", col = "col";

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d",&a[i][j]);

    if (n > m)
    {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
        {
            b[j][i] = a[i][j];
        }

        memcpy(a, b, sizeof(a));

        swap(n, m);
        swap(row, col);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum[j] += a[i][j];
        }
    }

    int mv = *min_element(sum, sum + m);

    for (int j = 0; j < m; j++)
    {
        int diff = sum[j] - mv;
        if (diff % n)
        {
            printf("-1\n");
            return 0;
        }
        diff /= n;
        for (int i = 0; i < diff; i++) ans.emplace_back(col, j + 1);
        for (int i = 0; i < n; i++)
        {
            if (a[i][j] < diff)
            {
                printf("-1\n");
                return 0;
            }

            a[i][j] -= diff;
        }
    }

    for (int i = 0; i < n; i++)
    {
        int v = a[i][0];
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] != v)
            {
                printf("-1\n");
                return 0;
            }
        }

        while (v--) ans.emplace_back(row, i + 1);
    }

    printf("%zd\n", ans.size());
    for (auto &e : ans) printf("%s %d\n", e.first.c_str(), e.second);
}