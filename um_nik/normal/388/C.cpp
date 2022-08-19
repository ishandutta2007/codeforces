#include <iostream>
#include <algorithm>
using namespace std;

int n;
int sc1, sc2;
int sz;
int s;
int a[200];
int b[200];

int main()
{
    sz = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s);
        for (int j = 0; j < s; j++)
            scanf("%d", &a[j]);
        if (s % 2 == 1)
        {
            b[sz] = a[s / 2];
            sz++;
        }
        for (int j = 0; j < s / 2; j++)
            sc1 += a[j];
        for (int j = (s + 1) / 2; j < s; j++)
            sc2 += a[j];
    }
    sort(b, b + sz);
    if (sz % 2 == 1)
    {
        for (int i = 0; i < sz; i++)
        {
            if (i % 2 == 0)
                sc1 += b[i];
            else
                sc2 += b[i];
        }
    }
    else
    {
        for (int i = 0; i < sz; i++)
        {
            if (i % 2 == 1)
                sc1 += b[i];
            else
                sc2 += b[i];
        }
    }
    printf("%d %d\n", sc1, sc2);
    return 0;
}