#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int x;
    scanf("%d", &x);
    if (x & 1)
    {
        printf("0\n");
        return 0;
    }
    x /= 2;
    printf("%d\n", (x - 1) / 2);

    return 0;
}