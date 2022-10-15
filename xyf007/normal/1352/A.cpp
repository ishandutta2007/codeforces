#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, ans[10];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int t = 1, cnt = 0;
        while (n)
        {
            if (n % 10)
            {
                ans[++cnt] = n % 10 * t;
            }
            n /= 10;
            t *= 10;
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= cnt; i++)
        {
            printf("%d ", ans[i]);
        }
        printf("\n");
    }
    return 0;
}