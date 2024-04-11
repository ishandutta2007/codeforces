#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 4040;
int n;
int m;
int v[N], d[N], p[N];
int ans[N];
bool used[N];
int q[N];
int topQ;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d%d%d", &v[i], &d[i], &p[i]);
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (used[i]) continue;
        ans[m++] = i + 1;
        int r = v[i];
        for (int j = i + 1; j < n && r > 0; j++)
        {
            if (used[j]) continue;
            p[j] -= r;
            if (p[j] < 0)
            {
                used[j] = 1;
                q[topQ++] = j;
            }
            r--;
        }
        while(k < topQ)
        {
            int v = q[k++];
            for (int j = v + 1; j < n; j++)
            {
                if (used[j]) continue;
                p[j] -= d[v];
                if (p[j] < 0)
                {
                    used[j] = 1;
                    q[topQ++] = j;
                }
            }
        }
    }
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
        printf("%d ", ans[i]);

    return 0;
}