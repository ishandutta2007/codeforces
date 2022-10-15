#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int q, a[500001], tmp[701][701];
int main(int argc, char const *argv[])
{
    scanf("%d", &q);
    while (q--)
    {
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        if (t == 1)
        {
            a[x] += y;
            for (int j = 1; j <= 700; j++)
            {
                tmp[j][x % j] += y;
            }
        }
        else
        {
            if (x <= 700)
            {
                printf("%d\n", tmp[x][y]);
            }
            else
            {
                int ans = 0;
                for (int j = y; j <= 500000; j += x)
                {
                    ans += a[j];
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}