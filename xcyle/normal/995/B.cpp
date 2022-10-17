#include <iostream>
#include <cstdio>
#define maxn 205
using namespace std;
int n, a[maxn];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++)
    {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int t = a[2 * i - 1];
        for (int j = 2 * i; j <= 2 * n; j++)
        {
            if(t == a[j])
            {
                ans += j - 2 * i;
                for (int k = j; k > 2 * i; k--)
                {
                    a[k] = a[k - 1];
                }
                break;
            }
        }
    }
    printf("%d", ans);
    return 0;
}