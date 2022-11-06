#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 20010
#define inf 1000000000

int n, nd, sol, dc;
int v[maxn], d[maxn], sp[maxn];

int main()
{
 //   freopen("data.in", "r", stdin);
 //   freopen("data.out", "w", stdout);

    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    for(int i=1; i*i<=n; ++i)
        if(n%i==0)
        {
            if(n/i>=3)
                d[++nd]=i;
            if(i>=3)
                d[++nd]=n/i;
        }

    sol=-inf;

    for(int i=1; i<=nd; ++i)
    {
        dc=d[i];
        for(int j=1; j<=n; ++j)
        {
            sp[j]=v[j];
            if(j>dc)
                sp[j]+=sp[j-dc];
            if(j>n-dc)
                sol=max(sol, sp[j]);
        }
    }

    printf("%d\n", sol);
    return 0;
}