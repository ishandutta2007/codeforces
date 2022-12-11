#include <bits/stdc++.h>
using namespace std;

int a[100005], s, n;
long long b[100005];

bool check(int t, bool print)
{
    for (int i = 1; i <= n; i++)
    {
        b[i] = a[i] + t * 1ll * i;
    }

    sort(b + 1, b + 1 + n);

    long long res = accumulate(b + 1, b + 1 + t, 0LL);
    if (res > s) return false;
    if (print)
    {
        printf("%d %lld\n", t, res);
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&s);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int lo = 1, hi = n, ans = 0;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (check(mid, false))
        {
            ans = mid; lo = mid + 1;
        }
        else hi = mid - 1;
    }

    check(ans, true);
}