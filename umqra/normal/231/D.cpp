#include <iostream>
using namespace std;
int a[10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif
    int sum = 0;
    int x, y, z;
    int x1, y1, z1;
    scanf("%d%d%d", &x, &y, &z);
    scanf("%d%d%d", &x1, &y1, &z1);
    for (int i = 1; i <= 6; i++)
        scanf("%d", &a[i]);

    if (y > y1)
        sum += a[2];
    if (y < 0)
        sum += a[1];

    if (z > z1)
        sum += a[4];
    if (z < 0)
        sum += a[3];

    if (x > x1)
        sum += a[6];
    if (x < 0)
        sum += a[5];
    printf("%d", sum);
    return 0;
}