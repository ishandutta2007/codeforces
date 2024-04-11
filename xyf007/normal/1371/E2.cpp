#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, p, a[100001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
void checkmin(int &x, int y)
{
    if (x > y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &p);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int minn = a[1], maxx = a[n], k = 0;
    for (int i = 1; i <= n; i = k + 1)
    {
        while (k < n && a[k + 1] == a[i])
        {
            k++;
        }
        checkmax(minn, a[i] - i + 1);
        if (k >= p)
        {
            checkmin(maxx, a[i] - k + p - 1);
        }
    }
    if (minn > maxx)
    {
        printf("0\n");
        return 0;
    }
    printf("%d\n", maxx - minn + 1);
    for (int i = minn; i <= maxx; i++)
    {
        printf("%d ", i);
    }
    return 0;
}