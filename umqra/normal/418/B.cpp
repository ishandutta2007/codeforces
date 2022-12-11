#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
using namespace std;

typedef long long ll;
const ll INF = (ll)2e18;

const int M = (1 << 20);
const int N = 200;

ll dp[M];
int x[N], k[N], pr[N];
int mask[N];
int perm[N];

bool cmp(int a, int b)
{
    return k[a] < k[b];
}

int main()
{
#ifdef UMQRA
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int n, m, b;
    scanf("%d%d%d", &n, &m, &b);

    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d", &x[i], &k[i], &pr[i]);
        for (int s = 0; s < pr[i]; s++)
        {
            int t;
            scanf("%d", &t);
            mask[i] |= (1 << (t - 1));
        }
    }   
    for (int i = 0; i < n; i++)
        perm[i] = i;
    sort(perm, perm + n, cmp);

    int maxM = (1 << m);
    fill(dp, dp + maxM, INF);
    dp[0] = 0;

    ll ans = INF;
    for (int i = 0; i < n; i++)
    {
        int ind = perm[i];
        for (int s = maxM - 1; s >= 0; s--)
        {              
            dp[s | mask[ind]] = min(dp[s | mask[ind]], dp[s] + x[ind]);
            if ((s | mask[ind]) == maxM - 1)
            {
                ans = min(ans, (ll)k[ind] * (ll)b + dp[s] + x[ind]);
            }
        }
    }
    if (ans == INF)
        cout << -1;
    else
        cout << ans;

    
    return 0;
}