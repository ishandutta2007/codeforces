#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int n;
int x = -1;

int main()
{
    scanf("%d", &n);
    while(n--)
    {
        int y;
        scanf("%d", &y);
        while(y % 2 == 0) y /= 2;
        while(y % 3 == 0) y /= 3;
        if (x == -1) x = y;
        if (x != y) x = -2;
    }
    if (x == -2)
        printf("No\n");
    else
        printf("Yes\n");

    return 0;
}