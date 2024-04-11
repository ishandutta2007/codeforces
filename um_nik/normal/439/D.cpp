#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n, m;
ll a[100100], b[100100];
ll c[200200];
ll sum_a[100100], sum_b[100100];
ll ans = (ll)1e18;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%I64d", &b[i]);
    for (int i = 0; i < n; i++)
        c[i] = a[i];
    for (int i = 0; i < m; i++)
        c[n + i] = b[i];
    sort(a, a + n);
    sort(b, b + m);
    reverse(b, b + m);
    sort(c, c + n + m);
    sum_a[0] = a[0];
    for (int i = 1; i < n; i++)
        sum_a[i] = sum_a[i - 1] + a[i];
    sum_b[0] = b[0];
    for (int i = 1; i < m; i++)
        sum_b[i] = sum_b[i - 1] + b[i];
    if (a[0] >= b[0])
    {
        printf("0\n");
        return 0;
    }
    int idx1 = 0;
    int idx2 = m - 1;
    for (int i = 0; i < n + m; i++)
    {
        if (i > 0 && c[i] == c[i - 1])
            continue;
        while (idx1 < n && a[idx1] < c[i])
            idx1++;
        while (idx2 >= 0 && b[idx2] <= c[i])
            idx2--;
        ll tmp = 0LL;
        if (idx1 > 0)
            tmp += c[i] * (ll)(idx1) - sum_a[idx1 - 1];
        if (idx2 >= 0)
            tmp += sum_b[idx2] - c[i] * (ll)(idx2 + 1);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
//  cin >> n;
    return 0;
}