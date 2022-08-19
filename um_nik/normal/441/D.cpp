#include <iostream>
using namespace std;

int n;
int m;
int p[4000];
bool u[4000];
int c;
int a[4000];

void make_move()
{
    for (int i = 1; i <= n; i++)
        u[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!u[i])
        {
            int x = i;
            u[x] = 1;
            x = p[x];
            if (!u[x])
            {
                int q = n + 1;
                while (!u[x])
                {
                    q = min(q, x);
                    u[x] = 1;
                    x = p[x];
                }
                printf("%d %d ", i, q);
                swap(p[i], p[q]);
                return;
            }
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &p[i]);
    scanf("%d", &m);
    m = n - m;
    for (int i = 1; i <= n; i++)
    {
        if (!u[i])
        {
            a[c++] = i;
            int x = i;
            while (!u[x])
            {
                u[x] = 1;
                x = p[x];
            }
        }
    }
    if (c == m)
    {
        printf("0\n");
        return 0;
    }
    if (c > m)
    {
        printf("%d\n", c - m);
        for (int i = 1; i <= c - m; i++)
            printf("%d %d ", a[0], a[i]);
        printf("\n");
        return 0;
    }
    printf("%d\n", m - c);
    for (; c < m; c++)
        make_move();
    printf("\n");
    return 0;
}