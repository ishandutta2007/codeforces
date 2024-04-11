#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[1001], ans[1001], tmp[1001];
void checkmin(int &x, int y)
{
    if (x > y)
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
    long long maxxx = 0;
    for (int i = 1; i <= n; i++)
    {
        int maxx = a[i];
        long long sum = a[i];
        tmp[i] = a[i];
        for (int j = i - 1; j >= 1; j--)
        {
            tmp[j] = min(a[j], maxx);
            sum += 1LL * tmp[j];
            checkmin(maxx, a[j]);
        }
        maxx = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            tmp[j] = min(a[j], maxx);
            sum += 1LL * tmp[j];
            checkmin(maxx, a[j]);
        }
        if (sum > maxxx)
        {
            for (int j = 1; j <= n; j++)
            {
                ans[j] = tmp[j];
            }
            maxxx = sum;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}