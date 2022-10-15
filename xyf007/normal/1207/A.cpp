#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        int b, p, f, h, c;
        scanf("%d%d%d%d%d", &b, &p, &f, &h, &c);
        b >>= 1;
        if (h > c)
        {
            if (b > p)
            {
                printf("%d\n", p * h + min((b - p), f) * c);
                continue;
            }
            else
            {
                printf("%d\n", b * h);
                continue;
            }
        }
        else
        {
            if (b > f)
            {
                printf("%d\n", f * c + min((b - f), p) * h);
                continue;
            }
            else
            {
                printf("%d\n", b * c);
                continue;
            }
        }
    }
    return 0;
}