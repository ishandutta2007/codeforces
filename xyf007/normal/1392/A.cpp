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
        bool f = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] != a[i + 1])
            {
                f = 0;
                printf("1\n");
                break;
            }
        }
        if (f)
        {
            printf("%d\n", n);
        }
    }
    return 0;
}