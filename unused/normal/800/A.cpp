#include <bits/stdc++.h>
using namespace std;

int a[100005], b[100005];
int n, p;

bool check(double t)
{
    double pl = p * t;
    double total = 0;
    for (int i = 0; i < n; i++)
    {
        total += max(0.0, a[i] * t - b[i]);
    }
    return total <= pl;
}

int main()
{
    scanf("%d%d",&n,&p);
    for (int i = 0; i < n; i++) scanf("%d%d",&a[i],&b[i]);
    if (accumulate(a, a + n, 0LL) <= p)
    {
        printf("-1\n");
        return 0;
    }

    double lo = 0, hi = 1e18;
    for (int i = 0; i <= 100; i++)
    {
        double mid = (lo + hi) / 2;
        if (check(mid)) lo = mid;
        else hi = mid;
    }

    printf("%.15f\n", (lo + hi) / 2);
}