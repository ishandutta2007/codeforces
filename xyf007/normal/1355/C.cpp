#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long A, B, C, D;
int main(int argc, char const *argv[])
{
    scanf("%lld%lld%lld%lld", &A, &B, &C, &D);
    long long ans = 0;
    for (int i = A; i <= B; i++)
    {
        if (i + B >= D + 1)
        {
            ans += (C - B + 1) * (D - C + 1);
        }
        else
        {
            if (i + B >= C + 1)
            {
                long long l = max(i + C - D, 1LL), r = C - B + 1;
                ans += (i + B - C - 1) * (C - B + 1) + (l + r) * (r - l + 1) / 2;
            }
            else
            {
                long long l = max(i + C - D, 1LL), r = i;
                ans += (l + r) * (r - l + 1) / 2;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}