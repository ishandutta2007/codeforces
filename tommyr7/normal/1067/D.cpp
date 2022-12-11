#include <bits/stdc++.h>
#define eps 1e-10
#define Maxn 200007
using namespace std;
int n;
long long T;
double M=0.0;
struct point
{
    double x,y;
    bool operator <(const point &p)
    const
    {
        return x<p.x;
    }
} que[Maxn];
struct matrix
{
    double a,b,c;
    long long r;
    matrix operator *(const matrix &p)
    const
    {
        return (matrix){1.0*a*p.a,1.0*a*p.b+b,1.0*a*p.c+1.0*b*p.r+c,r+p.r};
    }
} A[57];
int main()
{
    scanf("%d%lld",&n,&T);
    for (int i=1;i<=n;i++)
    {
        int a,b;
        double p;
        scanf("%d%d%lf",&a,&b,&p);
        M=max(M,1.0*b*p);
        que[i]=(point){p,1.0*a*p};
    }
    sort(que+1,que+n+1);
    int now=0;
    for (int i=1;i<=n;i++)
    {
        if (now>0&&que[i].x<que[now].x+eps&&que[i].y<=que[now].y) continue;
        if (now>0&&que[i].x<que[now].x+eps&&que[i].y>que[now].y) --now;
        while (now>1&&1.0*(que[i].y-que[now].y)*(que[now].x-que[now-1].x)>1.0*(que[now].y-que[now-1].y)*(que[i].x-que[now].x)) --now;
        que[++now]=que[i];
    }
    n=now;
    long long x=0;
    double ans=0.0;
    for (int i=1;i<=n&&x<T;i++)
    {
        if (i<n&&1.0*(que[i+1].x-que[i].x)*(1.0*M*x-ans)+que[i+1].y-que[i].y>0) continue;
        A[0]=(matrix){1.0-que[i].x,1.0*M*que[i].x,que[i].y,1};
        for (int j=1;j<=40;j++)
            A[j]=A[j-1]*A[j-1];
        for (int j=40;j>=0;j--)
            if (x+(1LL<<j)<T)
            {
                double tmp=1.0*A[j].a*ans+1.0*A[j].b*x+A[j].c;
                if (i==n||1.0*(que[i+1].x-que[i].x)*(1.0*M*(x+(1LL<<j))-tmp)+que[i+1].y-que[i].y<=0.0)
                {
                    x+=1LL<<j;
                    ans=tmp;
                }
            }
        ans=1.0*ans*A[0].a+1.0*x*A[0].b+A[0].c;
        ++x;
    }
    printf("%.9lf\n",ans);
    return 0;
}