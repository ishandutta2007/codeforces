#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, p;
int calc(int x)
{
    int sum = 0;
    while (x)
    {
        if (x & 1)
        {
            sum++;
        }
        x >>= 1;
    }
    return sum;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= 100; i++)
    {
        n -= p;
        if (n <= 0)
        {
            printf("-1");
            return 0;
        }
        if (calc(n) <= i && n >= i)
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}