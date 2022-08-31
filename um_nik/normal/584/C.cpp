#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;

const int N = 100100;
int n, k;
char a[N], b[N], c[N];
bool f[N];

int main()
{
    scanf("%d%d", &n, &k);
    scanf(" %s ", a);
    scanf(" %s ", b);
    int m = 0;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            m++;
            f[i] = 1;
        }
    if (m > 2 * k)
    {
        printf("-1\n");
        return 0;
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; i++)
    {
        if (!f[i]) continue;
        if (x == y && x + m <= k)
        {
            c[i] = 'a';
            while(c[i] == a[i] || c[i] == b[i])
                c[i]++;
            x++;
            y++;
        }
        else
        {
            if (x == y)
            {
                x++;
                c[i] = b[i];
            }
            else
            {
                y++;
                c[i] = a[i];
            }
        }
        m--;
    }
    for (int i = 0; i < n; i++)
    {
        if (f[i]) continue;
        if (x == k)
            c[i] = a[i];
        else
        {
            x++;y++;
            c[i] = 'a';
            while(c[i] == a[i]) c[i]++;
        }
    }
    c[n] = (char)0;
    printf("%s\n", c);

    return 0;
}