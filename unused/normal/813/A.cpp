#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d",&t);
        sum += t;
    }
    int m;
    scanf("%d",&m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d",&a,&b);
        if (b >= sum)
        {
            printf("%d\n", max(sum, a));
            return 0;
        }
    }

    printf("-1\n");
}