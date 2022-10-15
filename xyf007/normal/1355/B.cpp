#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, a[200001];
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        sort(a + 1, a + n + 1);
        int ans = 0, tmp = 0;
        for (int i = 1; i <= n; i++)
        {
            tmp++;
            if (tmp == a[i])
            {
                ans++;
                tmp = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}