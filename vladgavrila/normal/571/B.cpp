#include <cstdio>
#include <algorithm>

using namespace std;

#define maxn 300010
#define maxk 5010
#define inf 2000000010

int n, k, m, lg, pc;
int v[maxn];
int d[maxk][maxk];

int main()
{
    scanf("%d%d", &n, &k);

    lg=n/k;

    for(int i=1; i<=n; ++i)
        scanf("%d", &v[i]);

    sort(v+1, v+n+1);

    for(int i=0; i<=k; ++i)
        for(int j=0; j<=k; ++j)
            d[i][j]=inf;

    d[0][0]=0;

    lg=n/k;

    for(int i=1; i<=k; ++i)
        for(int j=0; j<=n%k; ++j)
        {
            pc=i*lg+j;
            if(d[i-1][j]!=inf)
                d[i][j]=d[i-1][j]+v[pc]-v[pc-lg+1];
            if(j>0)
            {
                if(d[i-1][j-1]!=inf)
                    d[i][j]=min(d[i][j], d[i-1][j-1]+v[pc]-v[pc-lg]);
            }
        }

    printf("%d\n", d[k][n%k]);

    return 0;
}