#include <stdio.h>

long long a[100005];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&a[i]);
    }

    if (n == 1)
    {
        printf("1 1\n0\n1 1\n0\n1 1\n%lld\n", -a[0]);
        return 0;
    }

    printf("1 %d\n", n);
    for (int i = 0; i < n; i++)
    {
        int rem = (a[i] % (n - 1) + (n - 1)) % (n - 1);
        if (rem == 0) printf("0 ");
        else
        {
            printf("%lld ", (n - 1 - rem) * 1ll * n);
            a[i] += (n - 1 - rem) * 1ll * n;
        }
    }
    printf("\n1 %d\n", n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        printf("%lld ", -a[i]);
    }
    printf("\n%d %d\n%lld\n", n, n, -a[n - 1]);
}