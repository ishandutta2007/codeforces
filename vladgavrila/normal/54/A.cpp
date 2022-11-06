#include <stdio.h>

using namespace std;

#define maxn 1001

int n, c, i, j, k, sol;
int v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d%d", &n, &k, &c);
    for(int i=1; i<=c; ++i)
        scanf("%d", &v[i]);

    for(int i=1; i<=c; ++i)
        sol=sol+1+(v[i]-v[i-1]-1)/k;
    sol=sol+(n-v[c])/k;

    printf("%d\n", sol);
    return 0;
}