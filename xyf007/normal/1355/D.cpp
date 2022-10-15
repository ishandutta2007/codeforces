#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n, s;
int main(int argc, char const *argv[])
{
    scanf("%d%d", &n, &s);
    if (n <= s / 2)
    {
        printf("YES\n");
        for (int i = 1; i < n; i++)
        {
            printf("1 ");
        }
        printf("%d\n%d\n", s - n + 1, s / 2);
    }
    else
    {
        printf("NO");
    }
    return 0;
}