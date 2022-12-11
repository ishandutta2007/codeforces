#include <iostream>
#include <algorithm>
using namespace std;

const int N = (int)1e5 + 100;

int a[N], q[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen ("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
#endif

    int k, n;
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
        scanf("%d", &q[i]);
    scanf("%d", &n);   
    for (int s = 0; s < n; s++)
        scanf("%d", &a[s]);
    sort(a, a + n);
    sort(q, q + k);

    int ind = n - 1;
    long long ans = 0;   
    for (int i = 0; i >= 0; i--)
    {
        while (q[i] <= n)
        {                                      
            for (int s = ind; s > ind - q[i]; s--)
                ans += a[s];
            ind -= q[i] + 2;
            n -= q[i] + 2;       
        }
    }

    for (int i = ind; i >= 0; i--)
        ans += a[i];

    cout << ans;
    return 0;
}