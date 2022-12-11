#include <bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    cin.sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int rem = a[0] % k;
    for (int i = 1; i < n; i++)
    {
        if (rem != a[i] % k)
        {
            printf("-1\n");
            return 0;
        }
    }

    int mv = *min_element(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (a[i] - mv) / k;
    }
    printf("%lld\n", ans);
}