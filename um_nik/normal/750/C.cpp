#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = (int)1e9;
const int C = 1900;
int max2 = -INF, min1 = INF;

int main()
{
    int x = 0;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int d, w;
        scanf("%d%d", &w, &d);
        if (d == 1)
            min1 = min(min1, x);
        else
            max2 = max(max2, x);
        x += w;
    }
    if (min1 <= max2)
    {
        printf("Impossible\n");
        return 0;
    }
    if (max2 == -INF)
    {
        printf("Infinity\n");
        return 0;
    }
    x += C - 1 - max2;
    printf("%d\n", x);

    return 0;
}