#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2;
    int x, y;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x,&y);

    if ((x2 - x1) % x || (y2 - y1) % y)
    {
        printf("NO\n");
        return 0;
    }

    int X = abs(x2 - x1) / x;
    int Y = abs(y2 - y1) / y;

    if (X % 2 == Y % 2) printf("YES\n");
    else printf("NO\n");
}