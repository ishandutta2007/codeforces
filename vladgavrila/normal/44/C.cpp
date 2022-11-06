#include <stdio.h>

using namespace std;

#define maxn 110

int n, a, b, i, j, k;
int f[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &k);
    for(int i=1; i<=k; ++i)
    {
        scanf("%d%d", &a, &b);
        for(int j=a; j<=b; ++j)
            f[j]++;
    }
    for(int i=1; i<=n; ++i)
    {
        if(f[i]!=1)
        {
            printf("%d %d\n", i, f[i]);
            return 0;
        }
    }
    printf("OK\n");
    return 0;
}