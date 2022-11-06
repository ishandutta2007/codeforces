#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, i, j, k;
double d[maxn][maxn];
long long l, r, p1, p2, nr, x;
double prob, sol;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    d[0][0]=1;
    for(int i=0; i<n; ++i)
    {
        p1=1;
        p2=2;
        scanf("%I64d%I64d", &l, &r);
        r++;
        nr=0;
        for(int i=0; i<=18; ++i)
        {
            x=min(r, p2)-max(l, p1);
            if(x>0)
                nr=nr+x;
            p1=p1*10;
            p2=p2*10;
        }
        prob=(double)nr/(r-l);
        for(int j=0; j<=i; ++j)
        {
            d[i+1][j+1]=d[i+1][j+1]+d[i][j]*prob;
            d[i+1][j]=d[i+1][j]+d[i][j]*(1-prob);
        }
    }
    scanf("%d", &k);
    sol=0;
    for(int j=0; j<=n; ++j)
    {
        if((double)n*k/100<=(double)j)
            sol=sol+d[n][j];
    }
    printf("%.11lf\n", sol);
    return 0;
}