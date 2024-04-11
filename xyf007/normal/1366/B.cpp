#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, m, x;
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &x, &m);
        int L = x, R = x;
        for (int i = 1; i <= m; i++)
        {
            int l, r;
            scanf("%d%d", &l, &r);
            if (l <= R && r >= L)
            {
                checkmin(L, l);
                checkmax(R, r);
            }
        }
        printf("%d\n", R - L + 1);
    }
    return 0;
}