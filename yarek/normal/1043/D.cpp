#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100001, M = 10, mod = 1000000007;
int base;
int a[M][N];
int pos[M][N];
ll hsh[M][N];
ll poww[N];
int n;

ll get(int k, int a, int b)
{
    if(a > b) return -1;
    a--;
    ll ans = (hsh[k][b] - hsh[k][a] * poww[b - a]) % mod;
    if(ans < 0) ans += mod;
    return ans;
}

int main()
{
    srand(chrono::steady_clock::now().time_since_epoch().count());
    base = 100001 + rand() % 100000;
    int m;
    scanf("%d %d", &n, &m);
    poww[0] = 1;
    for(int i = 1; i <= n; i++)
        poww[i] = poww[i-1] * base % mod;
    for(int i = 0; i < m; i++)
        for(int j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
            hsh[i][j] = (hsh[i][j-1] * base + a[i][j]) % mod;
            pos[i][a[i][j]] = j;
        }
    ll ans = 0;
    for(int i = 1, j = 1; j <= n; j++)
    {
        while(i < j)
        {
            int x = a[0][i], y = a[0][j];
            ll h = get(0, i, j);
            bool ok = true;
            for(int k = 1; k < m; k++)
                if(get(k, pos[k][x], pos[k][y]) != h)
                {
                    ok = false;
                    break;
                }
            if(ok) break;
            i++;
        }
        ans += (j - i + 1);
    }
    printf("%lld\n", ans);
}