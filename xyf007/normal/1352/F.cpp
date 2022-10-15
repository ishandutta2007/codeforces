#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n0, n1, n2;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n0, &n1, &n2);
        bool f = 1;
        if (n0)
        {
            for (int i = 0; i <= n0; i++)
            {
                printf("0");
            }
        }
        else
        {
            n1++;
        }
        if (n2)
        {
            for (int i = 0; i <= n2; i++)
            {
                printf("1");
            }
        }
        else
        {
            n1++;
            f = 0;
        }
        if (f)
        {
            for (int i = 1; i < n1; i++)
            {
                printf("%d", !(i & 1));
            }
        }
        else
        {
            for (int i = 1; i < n1; i++)
            {
                printf("%d", i & 1);
            }
        }
        printf("\n");
    }
    return 0;
}