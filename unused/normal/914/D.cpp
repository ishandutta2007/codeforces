#pragma GCC target("arch=ivybridge")
#include <bits/stdc++.h>
using namespace std;

int dat[1048576];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; i++)
        scanf("%d",&dat[i + 524288]);

    for (int i = 524287; i >= 1; i--)
    {
        dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);
    }

    int q;
    scanf("%d",&q);

    while (q--)
    {
        int type;
        scanf("%d",&type);
        if (type == 2)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            dat[524287 + x] = y;
            for (int i = 524287 + x >> 1; i >= 1; i >>= 1)
                dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);

            continue;
        }

        int ll, rr, x;
        scanf("%d%d%d",&ll,&rr,&x);

        int l = ll + 524287;
        int r = rr + 524287;

        int target = 0;

        while (l <= r)
        {
            if (l & 1)
            {
                if (dat[l] % x) target = l;
                ++l;
            }
            if (!(r & 1))
            {
                if (dat[r] % x)
                {
                    target = r;
                    break;
                }
                --r;
            }
            l >>= 1; r >>= 1;
        }

        if (target == 0)
        {
            printf("YES\n");
            continue;
        }

        while (target < 524288)
        {
            if (dat[target << 1] % x) target <<= 1;
            else target = target << 1 | 1;
        }

        int old = dat[target];
        dat[target] = x;

        for (int i = target >> 1; i >= 1; i >>= 1)
            dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);

        l = ll + 524287;
        r = rr + 524287;

        bool ans = true;

        while (l <= r)
        {
            if (l & 1)
            {
                if (dat[l] % x) { ans = false; break; }
                ++l;
            }
            if (!(r & 1))
            {
                if (dat[r] % x) { ans = false; break; }
                --r;
            }
            l >>= 1; r >>= 1;
        }

        dat[target] = old;
        for (int i = target >> 1; i >= 1; i >>= 1)
            dat[i] = gcd(dat[i << 1], dat[i << 1 | 1]);

        printf(ans ? "YES\n" : "NO\n");
    }
}