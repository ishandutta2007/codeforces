#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, k;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &k);
        if (k % (n - 1))
        {
            printf("%d\n", k / (n - 1) * n + k % (n - 1));
        }
        else
        {
            printf("%d\n", k / (n - 1) * n - 1);
        }
    }
    return 0;
}