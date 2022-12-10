#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...) 0
#endif



void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        k -= x;
    }
    while(k <= 0) k += n;
    printf("%d\n", k);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while(t--)
        solve();

    eprintf("time = %.3lf\n", (double)clock() / CLOCKS_PER_SEC);
}