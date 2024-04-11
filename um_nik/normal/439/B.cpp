#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll x;
ll ans;
ll a[100100];

int main()
{
    scanf("%d%I64d", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        ans += x * a[i];
        if (x > 1)
            x--;
    }
    printf("%I64d\n", ans);
    return 0;
}