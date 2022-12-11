#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

int main()
{
    int test;
    scanf("%d", &test);
    while(test--)
    {
        ull x, y, p, q;
        scanf("%llu %llu %llu %llu", &x, &y, &p, &q);
        //printf("%llu %llu %llu %llu\n", x, y, p, q);
        if(y * p == x * q)
            puts("0");
        else if(p == q || p == 0)
            puts("-1");
        else
        {
            ull ans = 0;
            if(x * q < y * p)
            {
                long double a = q - p, b = y * p - x * q;
                ull k = b / a;
                x += k;
                y += k;
                ans += k;
            }
            while(x * q < y * p)
            {
                x++;
                y++;
                ans++;
            }
            //printf("%Lf\n", (long double)x * q - (long double)y * p);
            ull k = p - (x % p);
            if(k == p) k = 0;
            //printf("%llu\n", k);
            ans += k;
            x += k;
            y += k;
            //printf("%Lf\n", (long double)x * q - (long double)y * p);
            //printf("%llu %llu\n", x, q);
            k = (long double)x * q / p - y;
            ans += k;
            y += k;
            while(y * p != x * q)
            {
                y++;
                ans++;
            }
            assert(y * p == x * q);
            printf("%llu\n", ans);
        }
    }
}