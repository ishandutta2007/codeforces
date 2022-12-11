#include <bits/stdc++.h>
using namespace std;

int x[1005];
double ans[1005];

int main()
{
    int n, r;
    scanf("%d%d",&n,&r);

    for (int i = 0; i < n; i++) scanf("%d",&x[i]);

    ans[0] = r;
    printf("%d ", r);

    for (int i = 1; i < n; i++)
    {
        ans[i] = r;
        for (int j = 0; j < i; j++)
        {
            if (abs(x[i] - x[j]) > 2 * r) continue;
            ans[i] = max(ans[i], ans[j] + sqrt(r * r * 4 - (x[i] - x[j]) * (x[i] - x[j])));
        }
        printf("%.9f ", ans[i]);
    }
}