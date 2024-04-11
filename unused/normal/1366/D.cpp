#include <bits/stdc++.h>
using namespace std;
 
int d[10000005];
int x[500005];
int y[500005];
 
int main()
{
    for (int i = 3; i <= 10000000; i += 2)
    {
        if (d[i]) continue;
        for (int j = i; j <= 10000000; j += i * 2) d[j] = i;
    }
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d", &x[i]);
    for (int i = 0; i < n; i++) y[i] = 1;
    for (int i = 0; i < n; i++)
    {
        int z = x[i] % 2 == 0 ? 2 : d[x[i]];
        while (x[i] % z == 0)
        {
            x[i] /= z;
            y[i] *= z;
        }
        if (x[i] == 1) x[i] = y[i] = -1;
    }
    for (int i = 0; i < n; i++) printf("%d ", x[i]); printf("\n");
    for (int i = 0; i < n; i++) printf("%d ", y[i]); printf("\n");
}