#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define id(x, y) (x) * (m + 1) + (y)
using namespace std;
int n, m, q, R[1100001], D[1100001], st[1100001], ed[1100001], tot;
char mp[11000000];
int read()
{
    char c = getchar();
    int s = 0;
    while (c < '0' || c > '9')
    {
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        s = s * 10 + c - '0';
        c = getchar();
    }
    return s;
}
int main()
{
    n = read();
    m = read();
    q = read();
    char ch;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            st[id(i, j)] = tot;
            ch = getchar();
            while (ch < '0' || ch > '9')
            {
                ch = getchar();
            }
            while (ch >= '0' && ch <= '9')
            {
                mp[tot++] = ch;
                ch = getchar();
            }
            ed[id(i, j)] = tot;
        }
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            int pos = id(i, j);
            R[pos] = id(i, j + 1);
            D[pos] = id(i + 1, j);
        }
    }
    int a, b, c, d, h, w, t1, t2, p1, p2;
    while (q--)
    {
        t1 = t2 = 0;
        a = read();
        b = read();
        c = read();
        d = read();
        h = read();
        w = read();
        for (int i = 1; i < a; i++)
        {
            t1 = D[t1];
        }
        for (int i = 1; i < b; i++)
        {
            t1 = R[t1];
        }
        for (int i = 1; i < c; i++)
        {
            t2 = D[t2];
        }
        for (int i = 1; i < d; i++)
        {
            t2 = R[t2];
        }
        p1 = t1;
        p2 = t2;
        for (int i = 1; i <= h; i++)
        {
            p1 = D[p1];
            p2 = D[p2];
            swap(R[p1], R[p2]);
        }
        for (int i = 1; i <= w; i++)
        {
            p1 = R[p1];
            p2 = R[p2];
            swap(D[p1], D[p2]);
        }
        p1 = t1;
        p2 = t2;
        for (int i = 1; i <= w; i++)
        {
            p1 = R[p1];
            p2 = R[p2];
            swap(D[p1], D[p2]);
        }
        for (int i = 1; i <= h; i++)
        {
            p1 = D[p1];
            p2 = D[p2];
            swap(R[p1], R[p2]);
        }
    }
    int pos = 1;
    for (int i = 1; i <= n; i++)
    {
        pos = D[pos];
        int now = pos;
        for (int j = 1; j <= m; j++)
        {
            for (int k = st[now]; k < ed[now]; k++)
            {
                putchar(mp[k]);
            }
            putchar(' ');
            now = R[now];
        }
        printf("\n");
    }
    return 0;
}