#include <bits/stdc++.h>
int main()
{
    int T; scanf("%d",&T); while (T--)
    {
        int x; scanf("%d",&x);
        for (int i = 2;; i++)
        {
            if (x % ((1 << i) - 1) == 0)
            {
                printf("%d\n", x / ((1 << i) - 1));
                break;
            }
        }
    }
}