#include <bits/stdc++.h>
using namespace std;

void recur(int n, long long k, int b)
{
    if (n == 0)
    {
        printf("\n");
        return;
    }

    long long sum = 0;

    for (int i = 1; i <= n; i++)
    {
        long long f = 1LL << max(0, min(n - i - 1, 62));
        if (sum + f >= k)
        {
            for (int j = i; j >= 1; j--) printf("%d ", b + j);
            recur(n - i, k - sum, b + i);
            return;
        }
        sum += f;
    }

    printf("-1\n");
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n; long long k;
        scanf("%d%lld",&n,&k);

        recur(n, k, 0);
    }
}