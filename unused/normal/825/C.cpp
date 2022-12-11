#include <bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int n; long long k;
    scanf("%d%lld",&n,&k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d",&a[i]);
    }

    sort(a, a + n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        while (a[i] > 2 * k)
        {
            ++ans;
            k *= 2;
        }

        k = max(k, a[i] * 1LL);
    }

    printf("%d\n", ans);
}