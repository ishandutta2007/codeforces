#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int tmp = n, ans = 0, t = 1;
        while (tmp > 9)
        {
            tmp /= 10;
            t = t * 10 + 1;
            ans += 9;
        }
        if (tmp * t <= n)
        {
            ans += tmp;
        }
        else
        {
            ans += tmp - 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}