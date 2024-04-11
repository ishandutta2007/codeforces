#include <stdio.h>
#include <algorithm>

using namespace std;

#define maxn 1010

int n, i, j, k, a, b;
int x[maxn], y[maxn];
double mn, mx, xx;

double intersectie(int a, int b)
{
    double rez, m, n;

    if(x[a]==x[b])
        return x[a];

    m=1.0*(y[a]-y[b])/(x[a]-x[b]);
    n=1.0*y[a]-m*x[a];
    return (1.0*y[1]-n)/m;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    #endif
    scanf("%d", &n);
    for(int i=1; i<=n; ++i)
    {
        scanf("%d%d", &x[i], &y[i]);
    }
    if(y[3]>y[1])
    {
        for(int i=2; i<=n; ++i)
        {
            x[i]=x[1]-(x[i]-x[1]);
            y[i]=y[1]-(y[i]-y[1]);
        }
    }

    x[n+1]=x[1];
    y[n+1]=y[1];
    mn=x[1];
    mx=x[2];

    for(int i=2; i<=n; ++i)
    {
        if(y[i]==y[i+1])
        {
            if(x[i]<x[i+1])
            {
                printf("0\n");
                return 0;
            }
            continue;
        }

        xx=intersectie(i, i+1);
        if(y[i]>y[i+1])
            mx=min(mx, xx);
        else
            mn=max(mn, xx);
       // printf("%.6lf\n", xx);
    }

  //  printf("%.6lf %.6lf\n", mn, mx);

    if(mn>mx)
    {
        printf("0\n");
        return 0;
    }

    for(int i=-2000100; i<=2000100; ++i)
    {
        if(i<mn)
            a=i;
        if(i<=mx)
            b=i;
    }
    a++;
    printf("%d\n", max(0, b-a+1));
    return 0;
}