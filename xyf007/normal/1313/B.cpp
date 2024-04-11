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
        int n, a, b, tmp;
        scanf("%d%d%d", &n, &a, &b);
        if (a == n && b == n)
        {
            printf("%d %d\n", n, n);
            continue;
        }
        if (a + b <= n)
        {
            printf("1 %d\n", a + b - 1);
        }
        else
        {
            printf("%d %d\n", a + b - n + 1, n);
        }
    }
    return 0;
}