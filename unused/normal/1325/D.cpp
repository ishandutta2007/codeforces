#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long x, s;
        scanf("%lld%lld", &x, &s);

        s -= x;
        if (s < 0 || s & 1)
        {
                printf("-1\n");
                return 0;
        }

        if (s == 0)
        {
                if (x == 0) printf("0\n");
                else printf("1\n%lld\n", x);
                return 0;
        }

        if (!(x & (s >> 1))) printf("2\n%lld %lld\n", (s >> 1) | x, (s >> 1));
        else printf("3\n%lld %lld %lld\n", x, s >> 1, s >> 1);
}