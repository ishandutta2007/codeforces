#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[101], b[101], f[101][10001];
void checkmax(int &x, int y)
{
    if (x < y)
    {
        x = y;
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d\n", &n);
    for (int i = 1; i <= n; i++)
    {
        char c = getchar();
        f[i][0] = c - '0';
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &a[i], &b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < b[i]; j++)
        {
            f[i][j] = f[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = b[i]; j <= 10000; j += a[i])
        {
            for (int k = 0; k < a[i] && j + k <= 10000; k++)
            {
                f[i][j + k] = f[i][j - 1] ^ 1;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= 10000; j++)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += f[i][j];
        }
        checkmax(ans, sum);
    }
    printf("%d", ans);
    return 0;
}