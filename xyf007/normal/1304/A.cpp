#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, x, y, a, b;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d%d", &x, &y, &a, &b);
        if ((y - x) % (a + b))
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", (y - x) / (a + b));
        }
    }
    return 0;
}