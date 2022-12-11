#include <bits/stdc++.h>
using namespace std;

struct comp
{
    bool operator()(long long a, long long b) const
    {
        long long X1 = 0, X2 = 0;
        while (a % 3 == 0) ++X1, a /= 3;
        while (b % 3 == 0) ++X2, b /= 3;
        if (X1 != X2) return X1 > X2;
        return a < b;
    }
};

long long dat[101];

int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld",&dat[i]);
    }

    sort(dat, dat + n, comp());
    for (int i = 0; i < n; i++) printf("%lld ", dat[i]);
    printf("\n");
}