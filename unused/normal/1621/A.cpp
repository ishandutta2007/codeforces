#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n, k;
        scanf("%d%d",&n,&k);
        if ((n + 1) / 2 < k) printf("-1\n");
        else
        {
            for (int x = 0; x < n; x++)
            {
                for (int y = 0; y < n; y++)
                {
                    if (x == y && x % 2 == 0 && x / 2 < k) printf("R");
                    else printf(".");
                }
                printf("\n");
            }
        }
    }
}