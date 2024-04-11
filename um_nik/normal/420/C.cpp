#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll n, p;
ll s[400100];
ll ans;
ll a[400100];
ll sums[400100];
ll b[400100];
pair<int, int> ed[400100];

int main()
{
    scanf("%I64d%I64d", &n, &p);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x > y)
            swap(x, y);
        s[x]++;
        s[y]++;
        ed[i] = make_pair(x, y);
    }
    for (int i = 0; i < n; i++)
        a[i] = s[i + 1];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        sums[a[i]]++;
        b[a[i]]++;
    }
    for (int i = 1; i <= n; i++)
        sums[i] += sums[i - 1];
/*  for (int i = 0; i <= n; i++)
    {
        printf("%I64d ", sums[i]);
    }*/
    for (int i = 0; i < n; i++)
    {
        int x = p - 1 - a[i];
        if (x < 0)
            ans += sums[n];
        else
            ans += sums[n] - sums[x];
        if (2 * a[i] >= p)
            ans--;
    }
/*  for (int i = 0; i <= n; i++)
    {
        if (2 * i >= p)
            ans -= b[i] * (b[i] - 1LL);
    }*/
    ans /= 2;
//  printf("%I64d\n", ans);
    sort(ed, ed + n);
    ll tmp = n + 1;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || ed[i] != ed[i - 1])
        {
            if (tmp < p)
                ans--;
            tmp = s[ed[i].first] + s[ed[i].second];
            if (tmp < p)
                ans++;
            tmp--;
        }
        else
        {
            tmp--;
        }
    }
    if (tmp < p)
        ans--;
    printf("%I64d\n", ans);
//  cin >> n;

    return 0;
}