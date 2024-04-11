#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, a, b;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    bool flip = false;

    if (x > y)
    {
        swap(x, y);
        swap(b, a);
        a = -a;
        b = -b;
        flip = true;
    }

    if (a <= y - x && y - x <= b)
    {
        printf("FIRST\n%d\n", flip ? x : y);
        return 0;
    }

    if (a <= 0 || a > y - x)
    {
        printf("DRAW\n");
        return 0;
    }

    int z2 = (y - x) % (a + b);
    if (z2 == 0)
    {
        printf("SECOND\n");
    }
    else if (a <= z2 && z2 <= b)
    {
        printf("FIRST\n%d\n", flip ? y - z2 : x + z2);
    }
    else
    {
        printf("DRAW\n");
    }

}