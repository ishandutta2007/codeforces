#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 2020;
int n;
int a[N];
int s[N];
int m;
int ans[N * N][2];
int c[N];
int k;

void read()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i] == s[j])
            {
                a[i] = j;
                break;
            }
    return;
}

void add(int x, int y)
{
    if (x > y) swap(x, y);
    ans[m][0] = x + 1;
    ans[m][1] = y + 1;
    m++;
    swap(a[x], a[y]);
    return;
}

int main()
{
    read();
    m = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
        res += abs(a[i] - i);
    printf("%d\n", res / 2);
    for (int x = 0; x < n; x++)
    {
        int idx = x;
        while(a[idx] != x) idx++;
        if (idx == x) continue;
        k = 0;
        c[k++] = x;
        int l = x;
        int r = a[x];
        while(r < idx)
        {
            int nxt = -1;
            for (int i = r; i > l; i--)
            {
                if (a[i] <= r) continue;
                nxt = i;
                r = a[i];
            }
            c[k++] = nxt;
        }
        c[k] = idx;
        for (int i = k - 1; i >= 0; i--)
            add(c[i], c[i + 1]);
    }
    printf("%d\n", m);
    for (int i = 0; i < m; i++)
        printf("%d %d\n", ans[i][0], ans[i][1]);

    return 0;
}