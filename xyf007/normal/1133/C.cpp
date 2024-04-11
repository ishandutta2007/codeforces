#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[200001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int l = 1, r = 1, ans = 0;
    while (r <= n)
    {
        while (r < n && a[r + 1] - a[l] <= 5)
        {
            r++;
        }
        checkmax(ans, r - l + 1);
        if (r == n)
        {
            break;
        }
        r++;
        while (l <= n && a[r] - a[l] > 5)
        {
            l++;
        }
        checkmax(ans, r - l + 1);
    }
    printf("%d", ans);
    return 0;
}