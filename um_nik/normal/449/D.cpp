#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MOD = (ll)(1e9 + 7);
int n;
int a[1 << 20][21];
ll st[1000100];
ll ans = 0LL;

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    st[0] = 1LL;
    for (int i = 1; i < 1000100; i++)
        st[i] = (st[i - 1] * 2LL) % MOD;
    for (int i = 0; i < 1000100; i++)
        st[i] = (st[i] - 1 + MOD) % MOD;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        a[x][0]++;
    }
    for (int mask = (1 << 20) - 1; mask >= 0; mask--)
    {
        int cnt = 0;
        for (int k = 0; k < 20; k++)
            if ( (mask & (1 << k)) == 0 )
                for (int i = 0; i < 19; i++)
                    a[mask][i + 1] += a[ mask | (1 << k) ][i];
            else
                cnt++;
        int x = 0;
        for (int i = 1; i < 20; i++)
            a[mask][i] = a[mask][i] / i;
        for (int i = 0; i < 20; i++)
            x += a[mask][i];
        if (cnt & 1)
            ans = (ans - st[x] + MOD) % MOD;
        else
            ans = (ans + st[x]) % MOD;
    }
    printf("%I64d\n", ans);

    return 0;
}