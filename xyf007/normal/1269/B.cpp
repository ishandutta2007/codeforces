#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, m, a[2001], b[2001], cnt1[4001], cnt2[2001], f1[2001];
void check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i] + x) % m;
    }
    sort(a + 1, a + n + 1);
    bool f = 1;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            f = 0;
            break;
        }
    }
    if (f)
    {
        printf("%d", x);
        exit(0);
    }
    for (int i = 1; i <= n; i++)
    {
        a[i] = (a[i] - x + m) % m;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &b[i]);
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int tmp = 1, tot = 0;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            tmp++;
        }
        else
        {
            cnt1[++tot] = tmp;
            f1[tot] = a[i - 1];
            tmp = 1;
        }
    }
    cnt1[++tot] = tmp;
    f1[tot] = a[n];
    for (int i = 1; i <= tot; i++)
    {
        cnt1[tot + i] = cnt1[i];
    }
    tmp = 1;
    tot = 0;
    for (int i = 2; i <= n; i++)
    {
        if (b[i] == b[i - 1])
        {
            tmp++;
        }
        else
        {
            cnt2[++tot] = tmp;
            tmp = 1;
        }
    }
    cnt2[++tot] = tmp;
    for (int i = 1; i <= tot; i++)
    {
        bool f = 1;
        for (int j = 0; j < tot; j++)
        {
            if (cnt1[i + j] != cnt2[j + 1])
            {
                f = 0;
                break;
            }
        }
        if (f)
        {
            check((b[1] - f1[i] + m) % m);
        }
    }
    return 0;
}