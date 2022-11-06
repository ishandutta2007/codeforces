#include <stdio.h>
#include <string.h>

using namespace std;

#define maxn 1010

int n, sum, nr, i, j, k, x, sol, v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &k);
    nr=n;
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);
    for(int i=k; i<=10000; ++i)
    {
        x=0;
        for(int j=1; j<=n; ++j)
            x=x+(v[j]/i)*i;
        if(x>sol)
            sol=x;
    }
    printf("%d\n", sol);
    return 0;
}