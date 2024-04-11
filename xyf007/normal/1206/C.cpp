#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, ans[200001];
int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    if (!(n % 2))
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for (int i = 1; i <= n; i++)
    {
        if (i & 1)
        {
            ans[i] = 2 * i - 1;
            ans[i + n] = 2 * i;
        }
        else
        {
            ans[i] = 2 * i;
            ans[i + n] = 2 * i - 1;
        }
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}