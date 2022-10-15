#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t;
long long a, b, n, m;
int main(int argc, char const *argv[])
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &n, &m);
        if (m <= min(a, b) && n + m <= a + b)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}