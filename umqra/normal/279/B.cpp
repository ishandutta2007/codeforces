#include <iostream>
#include <cstdio>
using namespace std;

const int N = (int)1e5 + 100;
int a[N];
int p[N];

int main()
{
    int n, t;
    cin >> n >> t;             

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    p[0] = a[0];
    for (int i = 1; i < n; i++)
        p[i] = p[i - 1] + a[i];

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int l = i - 1, r = n;
        int allS = (i == 0 ? 0 : p[i - 1]);
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (p[m] - allS <= t)
                l = m;
            else
                r = m;
        }
        ans = max(ans, l - i + 1);
    }
    cout << ans;
    return 0;
}