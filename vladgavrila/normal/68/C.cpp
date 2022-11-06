#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 10
#define maxd 210

int n, i, j, k, x, y, sol, cmax, f;
int mn[maxn][maxn], mx[maxn][maxn], ac[maxn][maxn];
int d[maxn][maxd], flux[maxn];

int back(int a, int b, int cost)
{
    int rez=0;
    if(a==n)
    {
        cmax=max(cmax, cost);
        return 1;
    }

    /*if(f==1)
    {
        printf("%d %d %d\n", a, b, mn[a][b], flux[a]);
    }*/

    int cc;
    if(b==n)
    {
        int aux=flux[a];
        if(flux[a]>mx[a][b] || flux[a]<mn[a][b])
            return 0;
        cc=flux[a]*flux[a];
        if(flux[a]>0)
            cc+=ac[a][b];
        flux[b]+=flux[a];
        flux[a]=0;
        rez=back(a+1, a+2, cost+cc);
        flux[a]=aux;
        flux[b]-=flux[a];
        return rez;
    }

    for(int i=mn[a][b]; i<=min(mx[a][b], flux[a]); ++i)
    {
        flux[a]-=i;
        flux[b]+=i;
        cc=i*i;
        if(i>0)
            cc+=ac[a][b];
        rez=max(rez, back(a, b+1, cost+cc));
        flux[a]+=i;
        flux[b]-=i;
    }
    return rez;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n*(n-1)/2; ++i)
    {
        scanf("%d%d", &x, &y);
        scanf("%d%d%d", &mn[x][y], &mx[x][y], &ac[x][y]);
    }

    for(f=0; f<30; ++f)
    {
        for(int j=1; j<=n; ++j)
        {
            flux[j]=0;
        }
        cmax=0;
        flux[1]=f;
        if(back(1, 2, 0))
        {
            printf("%d %d\n", f, cmax);
            return 0;
        }
    }
    printf("-1 -1\n");
    return 0;
}