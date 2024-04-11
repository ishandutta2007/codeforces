#include <bits/stdc++.h>
using namespace std;

int z[105];
bool used[105];

int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    int last = -1;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);

        if (last != -1)
        {
            int diff = (x + n - last + n - 1) % n + 1;
            if (z[last] == 0)
            {
                if (used[diff])
                {
                    printf("-1\n");
                    return 0;
                }
                z[last] = diff;
                used[diff] = true;
            }
            else if (z[last] != diff)
            {
                printf("-1\n");
                return 0;
            }
        }

        last = x;
    }

    for (int i = 1, j = 1; i <= n; i++)
    {
        if (z[i]) printf("%d ", z[i]);
        else
        {
            while (used[j]) ++j;
            printf("%d ", j);
            used[j] = true;
        }
    }

    printf("\n");
}