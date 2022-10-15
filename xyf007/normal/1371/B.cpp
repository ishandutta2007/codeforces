#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, r;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &r);
        if (r < n)
        {
            printf("%lld\n", 1LL * r * (r + 1) / 2);
        }
        else
        {
            printf("%lld\n", 1LL * n * (n - 1) / 2 + 1);
        }
    }
    return 0;
}