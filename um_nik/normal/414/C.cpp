#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m;
ll ans[25];
ll rev[25];
int a[2000000];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < (1 << n); i++)
        scanf("%d", &a[i]);
    
    for (int i = 1; i <= n; i++)
    {
        for (int x = 0; x < (1 << n); x += (1 << i))
        {
            ll it1 = x;
            ll tmp = x + (1 << (i - 1));
            for (int it2 = tmp; it2 < x + (1 << i); it2++)
            {
                while (it1 < tmp && a[it1] <= a[it2])
                    it1++;
                ans[i] += tmp - it1;
            }
            inplace_merge(a + x, a + x + (1 << (i - 1)), a + x + (1 << i));
            for (int it = x; it < x + (1 << i); it++)
            {
                if (it > x && a[it] == a[it - 1])
                    continue;
                ll tmp = it;
                while ((tmp < x + (1 << i)) && (a[tmp] == a[it]))
                    tmp++;
                tmp -= (ll)it;
                rev[i] -= tmp * (tmp - 1LL) / 2LL;
            }
        }
    }
    for (int i = n; i > 0; i--)
    {
        rev[i] -= rev[i - 1];
        ll x = (ll)(1 << (i - 1));
        ll y = (ll)(1 << (n - i));
        rev[i] += x * x * y;
    }

    scanf("%d", &m);
    for (int j = 0; j < m; j++)
    {
        int q;
        scanf("%d", &q);
        ll sum = 0LL;
        for (int i = 0; i <= q; i++)
            ans[i] = rev[i] - ans[i];
        for (int i = 0; i <= n; i++)
            sum += ans[i];
        printf("%I64d\n", sum);
    }

    return 0;
}