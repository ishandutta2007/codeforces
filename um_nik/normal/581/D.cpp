#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
#define mp make_pair
#define X first
#define Y second

struct Item
{
    int x, y;
    char c;

    Item() : x(), y(), c() {}

    void scan(int i)
    {
        c = 'A' + i;
        scanf("%d%d", &x, &y);
        if (x < y) swap(x, y);
    }

    bool operator < (const Item &I) const
    {
        if (x != I.x) return x > I.x;
        return y > I.y;
    }
};

Item a[5];

int main()
{
    for (int i = 0; i < 3; i++)
        a[i].scan(i);
    sort(a, a + 3);
    int s = 0;
    for (int i = 0; i < 3; i++)
        s += a[i].x * a[i].y;
    int n = 0;
    while(n * n < s) n++;
    if (n * n != s)
    {
        printf("-1\n");
        return 0;
    }
    if (a[0].x != n)
    {
        printf("-1\n");
        return 0;
    }
    if (a[1].x == n && a[2].x == n)
    {
        printf("%d\n", n);
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < a[i].y; j++)
            {
                for (int k = 0; k < n; k++)
                    printf("%c", a[i].c);
                printf("\n");
            }
        }
        return 0;
    }
    int m = n - a[0].y;
    for (int i = 1; i < 3; i++)
    {
        if (a[i].x != m) swap(a[i].x, a[i].y);
        if (a[i].x != m)
        {
            printf("-1\n");
            return 0;
        }
    }
    printf("%d\n", n);
    for (int i = 0; i < a[0].y; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%c", a[0].c);
        printf("\n");
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < a[1].y)
                printf("%c", a[1].c);
            else
                printf("%c", a[2].c);
        }
        printf("\n");
    }

    return 0;
}