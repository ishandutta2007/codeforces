#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, a, b, c;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &a, &b, &c);
        int l = 0, r = c, best = -1;
        while (l <= r)
        {
            int mid = l + ((r - l) >> 1);
            if (a + mid > b + c - mid)
            {
                best = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (best == -1)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", c - best + 1);
        }
    }
    return 0;
}