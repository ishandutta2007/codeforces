#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

const int N = 100100;
int n;
int b[20];
int k;

int main()
{
    scanf("%d%d", &n, &k);
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        b[x % 10]++;
        sum += 100 - x;
        ans += x / 10;
    }
    if (sum <= k)
    {
        printf("%d\n", 10 * n);
        return 0;
    }
    for (int x = 9; x >= 0; x--)
    {
        int y = (10 - x) * b[x];
        if (y <= k)
        {
            ans += b[x];
            k -= y;
        }
        else
        {
            ans += k / (10 - x);
            k = 0;
        }
    }
    ans += k / 10;
    printf("%d\n", ans);

    return 0;
}