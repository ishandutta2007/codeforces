#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, a[101];
bool f[101];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!f[i])
        {
            ans++;
            for (int j = i + 1; j <= n; j++)
            {
                if (!(a[j] % a[i]))
                {
                    f[j] = 1;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}