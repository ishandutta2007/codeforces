#include <bits/stdc++.h>
using namespace std;

int sign(int x)
{
    return x > 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        long long a = 0;
        int v = 0, n;
        scanf("%d",&n);
        for (int i = 0; i < n; i++)
        {
            int x;
            scanf("%d",&x);
            if (v == 0) v = x;
            if (sign(v) == sign(x))
            {
                v = max(v, x);
            }
            else
            {
                a += v;
                v = x;
            }
        }
        printf("%lld\n", a + v);
    }
}