#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int T; scanf("%d",&T); while (T--)
    {
        int x; scanf("%d",&x);
        if (x % 4 == 2)
        {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        long long sum = 0;
        for (int i = 0; i < x / 2; i++)
        {
            printf("%d ", i * 2 + 2);
            sum += i * 2 + 2;
        }
        for (int i = 1; i < x / 2; i++)
        {
            printf("%d ", i * 2 - 1);
            sum -= i * 2 - 1;
        }
        printf("%d\n", sum);
    }
}