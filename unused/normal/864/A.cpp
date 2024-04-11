#include <bits/stdc++.h>
using namespace std;
int z[105];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d",&t);
        z[t]++;
    }

    for (int i = 1; i <= 100; i++) for (int j = 1; j <= 100; j++)
    {
        if (i != j && z[i] == z[j] && z[i] + z[j] == n)
        {
            printf("YES\n%d %d\n", i, j);
            return 0;
        }
    }
    printf("NO\n");
}