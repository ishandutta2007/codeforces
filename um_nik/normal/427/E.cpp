#include <iostream>
using namespace std;
typedef long long ll;

int n, m;
ll ans = (ll)1e18;
ll a[1000100];
ll sum_l[1000100][2];
ll sum_r[1000100][2];

int main()
{
//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%I64d\n", &a[i]);
    sum_l[0][0] = a[0];
    sum_l[0][1] = 1;
    for (int i = 1; i < n; i++)
    {
        if (i % m == 0)
        {
            sum_l[i][0] = a[i] + sum_l[i - m][0];
            sum_l[i][1] = sum_l[i - 1][1] + 1LL;
        }
        else
        {
            sum_l[i][0] = sum_l[i - 1][0];
            sum_l[i][1] = sum_l[i - 1][1];
        }
    }
    sum_r[n - 1][0] = a[n - 1];
    sum_r[n - 1][1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if ((n - 1 - i) % m == 0)
        {
            sum_r[i][0] = a[i] + sum_r[i + m][0];
            sum_r[i][1] = sum_r[i + 1][1] + 1LL;
        }
        else
        {
            sum_r[i][0] = sum_r[i + 1][0];
            sum_r[i][1] = sum_r[i + 1][1];
        }
    }
    for (int i = 0; i < n; i++)
    {
        ll tmp = sum_l[i][1] * a[i] - sum_l[i][0] + sum_r[i][0] - sum_r[i][1] * a[i];
        ans = min(ans, tmp);
    }
    printf("%I64d\n", 2LL * ans);

    return 0;
}