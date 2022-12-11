#include <bits/stdc++.h>
using namespace std;

char dat[105];

int calc()
{
    int ret = 0;
    char z[2] {'V', 'K'};
    int p = 0;
    for (int i = 0; dat[i]; i++)
    {
        if (dat[i] == z[p])
        {
            ret += p;
            p ^= 1;
        }
    }
    return ret;
}

int main()
{
    scanf("%s",dat);
    int ans = calc();
    for (int i = 0; dat[i]; i++)
    {
        if (dat[i] == 'V') dat[i] = 'K';
        else dat[i] = 'V';

        ans = max(ans, calc());
        if (dat[i] == 'K') dat[i] = 'V';
        else dat[i] = 'K';
    }

    printf("%d\n", ans);
}