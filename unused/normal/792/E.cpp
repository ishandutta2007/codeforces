#include <bits/stdc++.h>
using namespace std;

int dat[505];
int n;
long long ans = 1e18;

void process(long long a)
{
    if (a <= 0) return;

    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        int X = dat[i];
        long long L = (X - (X + a) / (a + 1) * a);
        long long K = (-X + (X + a) / (a + 1) * (a + 1));
        if (L < 0 || K < 0) return;

        sum += L + K;
    }
    ans = min(ans, sum);
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; i++) scanf("%d",&dat[i]);
    int minval = *min_element(dat, dat + n);

    process(minval);
    process(minval - 1);

    for (int i = 1; i * i <= minval; i++)
    {
        process(i-1);
        process(i);
        process(i+1);
        process(minval / i - 1);
        process(minval / i);
        process(minval / i + 1);
    }

    printf("%lld\n", ans);
}