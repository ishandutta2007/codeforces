#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif



void solve()
{
    int n;
    scanf("%d", &n);
    if (n & 1)
    {
        printf("%d\n", n / 2);
        return;
    }
    n /= 2;
    int k = 0;
    while((1 << (k + 1)) <= n) k++;
    n -= 1 << k;
    printf("%d\n", n);
    return;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}