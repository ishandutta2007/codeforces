#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, p, a[100001];
bool check(int x)
{
    int t = 0;
    for (int i = 1; i <= n; i++)
    {
        while (t < n && a[t + 1] <= x)
        {
            t++;
        }
        if (t - i + 1 >= p || t < i)
        {
            return 0;
        }
        x++;
    }
    return 1;
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = a[1]; i <= a[n]; i++)
    {
        if (check(i))
        {
            ans++;
        }
    }
    printf("%d\n", ans);
    for (int i = a[1]; i <= a[n]; i++)
    {
        if (check(i))
        {
            printf("%d ", i);
        }
    }
    return 0;
}