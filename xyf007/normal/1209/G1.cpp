#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, q, a[200001], r[200001], cnt[200001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        checkmax(r[a[i]], i);
        cnt[a[i]]++;
    }
    int last = 1, now = 1, sum = 0, ans = n;
    while (last <= n)
    {
        while (now <= last)
        {
            checkmax(sum, cnt[a[now]]);
            checkmax(last, r[a[now]]);
            now++;
        }
        ans -= sum;
        sum = 0;
        last++;
    }
    printf("%d", ans);
    return 0;
}