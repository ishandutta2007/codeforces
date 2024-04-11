#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n;
int ans;
int a[200100];
int b[1000100];
int INF = (int)1e6 + 1;
int MAGIC = 1000;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    n = unique(a, a + n) - a;
    a[n] = INF;
    int it = 1;
    int x = -1;
    for (int i = 0; i <= n; i++)
    {
        while (it < a[i])
        {
            b[it++] = x;
        }
        x = a[i];
    }
    b[INF] = a[n - 1];
    for (int i = 0; i < n; i++)
    {
        if (a[i] < MAGIC)
        {
            for (int j = i + 1; j < n; j++)
                ans = max(ans, a[j] % a[i]);
        }
        else
        {
            for (int k = 2; a[i] * (k - 1) < INF; k++)
            {
                int x = b[ min(a[i] * k - 1, INF) ];
                ans = max(ans, x - a[i] * (k - 1));
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}