#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;
    
typedef long long ll;
const ll INF = (ll)1e18;
const int N = (int)1e6 + 100;
ll sum[N];
int a[N];
ll cnt[N];
ll ans[N];

int main()
{
//  freopen ("input.txt", "r", stdin);
//  freopen ("output.txt", "w", stdout); 
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    ll lst = -INF;
    int l = -1;
    for (int i = 0; i <= n; i++)
    {
        if (i == n || lst != a[i])
        {
            int t = l - m;
            ll a1 = 0, a2 = 0;
            if (t >= 0 && l > -1)
                a1 = 2 * (cnt[t % m] * lst - sum[t % m]);
            if (t % m != 0 && l > -1)
                a1 += 2 * (lst - a[0]);
            a2 = 2 * (cnt[0] * lst - sum[0]);
            ans[l] += min(a1, a2);
            for (int s = (l == -1 ? 0 : l); s < i; s++)
            {
                sum[s % m] += a[s];
                cnt[s % m]++;
            }
            lst = a[i];
            l = i;
        }   
    }
//  for (int i = 0; i < n; i++)
//      cout << ans[i] << ' ';
//  cout << endl;
    lst = INF;
    l = n;       
    memset(sum, 0, sizeof(sum));
    memset(cnt, 0, sizeof(cnt));

    for (int i = n - 1; i >= -1; i--)
    {
        if (i == -1 || lst != a[i])
        {
            int t = l + m;
            ll a1 = 0, a2 = 0;
            if (l != n)
                a1 += 2 * (sum[t % m] - cnt[t % m] * lst);
            if (t % m != (n - 1) % m && l != n)
                a1 += 2 * (a[n - 1] - lst);
            a2 = 2 * (sum[(n - 1) % m] - cnt[(n - 1) % m] * lst);

            ans[i + 1] += min(a1, a2);
            for (int s = (l == n ? n - 1 : l); s > i; s--)
            {
                sum[s % m] += a[s];
                cnt[s % m]++;
            }
            if (i != -1)
            {
                lst = a[i];
                l = i;
            }
        }
    }
    lst = INF;
//  for (int i = 0; i < n; i++)
//      cout << ans[i] << ' ';
//  cout << endl;
    ll res = INF;
    for (int i = 0; i < n; i++)
    {
        if (lst != a[i])
        {
            res = min(res, ans[i]);
            lst = a[i];
        }
    }
    cout << res;

    return 0;
}