#include <bits/stdc++.h>
using namespace std;

int a[200005];

int main()
{
    cin.sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    double total = 0.0;
    long long now = 0;
    for (int i = 1; i <= k; i++)
    {
        now += a[i];
    }
    for (int i = k + 1; i <= n + 1; i++)
    {
        total += now / (double)(n - k + 1);
        now += a[i] - a[i - k];
    }
    printf("%.9f\n", total);
}