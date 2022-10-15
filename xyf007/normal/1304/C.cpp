#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int q, n, m, t[101], l[101], r[101];
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
    scanf("%d", &q);
    while (q--)
    {
        scanf("%d%d", &n, &m);
        int maxx = m, minn = m, last = 0;
        bool f = 1;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d%d", &t[i], &l[i], &r[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            maxx += t[i] - last;
            minn -= t[i] - last;
            if (maxx < l[i] || minn > r[i])
            {
                printf("NO\n");
                f = 0;
                break;
            }
            checkmax(minn, l[i]);
            checkmin(maxx, r[i]);
            last = t[i];
        }
        if (f)
        {
            printf("YES\n");
        }
    }
    return 0;
}