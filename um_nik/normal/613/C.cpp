#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int gcd(int x, int y)
{
    return (y == 0 ? x : gcd(y, x % y));
}

const int N = (int)1e6 + 100;
int a[30];
int n;
int m = 0;
char s[N];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        m += a[i];
    if (n == 1)
    {
        printf("%d\n", m);
        for(int i = 0; i < m; i++)
            s[i] = 'a';
        s[m] = (char)0;
        printf("%s\n", s);
        return 0;
    }
    int cntOdd = 0;
    for (int i = 0; i < n; i++)
        if (a[i] & 1) cntOdd++;
    if (cntOdd > 1)
    {
        printf("0\n");
        int idx = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < a[i]; j++)
                s[idx++] = (char)('a' + i);
        s[m] = (char)0;
        printf("%s\n", s);
        return 0;
    }
    if (cntOdd == 1)
    {
        int g = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & 1)
                g = gcd(g, a[i]);
            else
                g = gcd(g, a[i] / 2);
        }
        printf("%d\n", g);
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & 1) continue;
            for (int j = 0; j < a[i] / 2 / g; j++)
                s[idx++] = (char)('a' + i);
        }
        for (int i = 0; i < n; i++)
        {
            if ((a[i] & 1) == 0) continue;
            for (int j = 0; j < a[i] / g; j++)
                s[idx++] = (char)('a' + i);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (a[i] & 1) continue;
            for (int j = 0; j < a[i] / 2 / g; j++)
                s[idx++] = (char)('a' + i);
        }
        int p = idx;
        for (int i = p; i < m; i++)
            s[i] = s[i - p];
        s[m] = (char)0;
        printf("%s\n", s);
        return 0;
    }
    int g = 0;
    for (int i = 0; i < n; i++)
        g = gcd(g, a[i] / 2);
    printf("%d\n", 2 * g);
    int idx = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < a[i] / 2 / g; j++)
            s[idx++] = (char)('a' + i);
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < a[i] / 2 / g; j++)
            s[idx++] = (char)('a' + i);
    int p = idx;
    for (int i = p; i < m; i++)
        s[i] = s[i - p];
    s[m] = (char)0;
    printf("%s\n", s);

    return 0;
}