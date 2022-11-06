#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 2010

int n, i, j, k, sol;
int v[maxn];

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d%d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d", &v[i]);
    }
    sol=k;
    for(int i=1; i<=n; ++i)
    {
        for(int j=i+1; j<=n; ++j)
        {
            sol=max(sol, k%v[i]+k/v[i]*v[j]);
        }
    }
    printf("%d\n", sol);
    return 0;
}