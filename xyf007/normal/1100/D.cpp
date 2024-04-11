#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
struct rook
{
    int x, y;
} a[1001];
int x, y;
bool vis[1001][1001];
void move(int dx, int dy)
{
    int k, tx, ty;
    if (vis[x + dx][y + dy])
    {
        dy = 0;
    }
    x += dx;
    y += dy;
    printf("%d %d\n", x, y);
    fflush(stdout);
    scanf("%d%d%d", &k, &tx, &ty);
    if (k == -1)
    {
        exit(0);
    }
    if (!k)
    {
        exit(0);
    }
    vis[a[k].x][a[k].y] = 0;
    a[k].x = tx;
    a[k].y = ty;
    vis[tx][ty] = 1;
}
int main()
{
    scanf("%d%d", &x, &y);
    for (int i = 1; i <= 666; i++)
    {
        scanf("%d%d", &a[i].x, &a[i].y);
        vis[a[i].x][a[i].y] = 1;
    }
    while (x < 500)
    {
        move(1, 0);
    }
    while (x > 500)
    {
        move(-1, 0);
    }
    while (y < 500)
    {
        move(0, 1);
    }
    while (y > 500)
    {
        move(0, -1);
    }
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    for (int i = 1; i <= 999; i++)
    {
        for (int j = 1; j <= 999; j++)
        {
            if (i < 500 || j < 500)
            {
                sum1 += vis[i][j];
            }
            if (i < 500 || j > 500)
            {
                sum2 += vis[i][j];
            }
            if (i > 500 || j < 500)
            {
                sum3 += vis[i][j];
            }
            if (i > 500 || j > 500)
            {
                sum4 += vis[i][j];
            }
        }
    }
    if (sum1 >= 500)
    {
        while (1)
        {
            move(-1, -1);
        }
    }
    if (sum2 >= 500)
    {
        while (1)
        {
            move(-1, 1);
        }
    }
    if (sum3 >= 500)
    {
        while (1)
        {
            move(1, -1);
        }
    }
    if (sum4 >= 500)
    {
        while (1)
        {
            move(1, 1);
        }
    }
    return 0;
}