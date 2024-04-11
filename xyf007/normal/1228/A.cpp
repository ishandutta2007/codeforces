#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int l, r;
bool check(int x)
{
    bool f[10];
    memset(f, 0, sizeof(f));
    while (x)
    {
        if (!f[x % 10])
        {
            f[x % 10] = 1;
        }
        else
        {
            return 0;
        }
        x /= 10;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &l, &r);
    for (int i = l; i <= r; i++)
    {
        if (check(i))
        {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}