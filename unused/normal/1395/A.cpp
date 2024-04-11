#include <stdio.h>
int main()
{
    int T; scanf("%d",&T); while (T--)
    {
        int a, b, c, d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        if ((a & 1) + (b & 1) + (c & 1) + (d & 1) <= 1)
        {
            printf("Yes\n");
            continue;
        }
        if (a && b && c) --a, --b, --c, ++d, ++d, ++d;
        if ((a & 1) + (b & 1) + (c & 1) + (d & 1) <= 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}