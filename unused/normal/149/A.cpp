#include <bits/stdc++.h>
using namespace std;

int dat[12];

int main()
{
    int k;
    scanf("%d",&k);
    for (int i = 0; i < 12; i++) scanf("%d",&dat[i]);
    sort(dat,dat+12);
        for (int i = 12; i >= 0; i--)
        {
            if (accumulate(dat+i, dat+12,0) >= k)
            {
                printf("%d\n", 12 - i);
                return 0;
            }
    }
    printf("-1\n");
}