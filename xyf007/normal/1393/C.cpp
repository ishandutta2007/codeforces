#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[100001], cnt[100001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(cnt, 0, sizeof(cnt));
        scanf("%d", &n);
        int maxx = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d", &x);
            a[x]++;
            checkmax(maxx, a[x]);
        }
        for (int i = 1; i <= n; i++)
        {
            cnt[a[i]]++;
        }
        printf("%d\n", (n - cnt[maxx] * maxx) / (maxx - 1) + cnt[maxx] - 1);
    }
    return 0;
}