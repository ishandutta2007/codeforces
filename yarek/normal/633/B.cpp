#include <cstdio>

int main()
{
    int m;
    scanf("%d", &m);
    int k = 0, first = 0, last = -1;
    for(int i = 5; k <= m; i++)
    {
        int l = i;
        while(l % 5 == 0)
        {
            l /= 5;
            k++;
        }
        if(k == m)
        {
            if(first == 0) first = i;
            last = i;
        }
    }
    printf("%d\n", last - first + 1);
    for(int i = first; i <= last; i++)
        printf("%d ", i);
    puts("");
}