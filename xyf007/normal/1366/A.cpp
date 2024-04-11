#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, a, b;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &a, &b);
        if (max(a, b) >= 2 * min(a, b))
        {
            printf("%d\n", min(a, b));
        }
        else
        {
            printf("%d\n", (a + b) / 3);
        }
    }
    return 0;
}