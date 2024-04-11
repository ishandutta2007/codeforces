#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

struct point
{int x,y;
};
struct point a[100010],p;

int n;
double m1,m2,pi=acos(-1),eps=1e-8;

double dis(point p1,point p2)
{return sqrt((double)(p1.x-p2.x)*(p1.x-p2.x)+(double)(p1.y-p2.y)*(p1.y-p2.y));
}

double calc(point p,double A,double B,double C)
{return fabs((A*p.x+B*p.y+C)/sqrt(A*A+B*B));
}

int mul(point p0,point p1,point p2)
{return ((long long)(p1.x-p0.x)*(p2.x-p0.x)+(long long)(p1.y-p0.y)*(p2.y-p0.y))>=0;
}

int main()
{int i,j;
 double d1,d2,k;
 
 scanf("%d%d%d",&n,&p.x,&p.y);
 for(i=1;i<=n;i++)
    scanf("%d%d",&a[i].x,&a[i].y);
 m2=1e18;
 for(i=1;i<=n;i++)
 {  d1=dis(a[i],p);
    if(a[i%n+1].x!=a[i].x)
    {   k=(double)(a[i%n+1].y-a[i].y)/(a[i%n+1].x-a[i].x);
        d2=calc(p,k,-1,a[i].y-k*a[i].x);
    }
    else
        d2=calc(p,1,0,-a[i].x);
    m1=max(m1,d1);
    m2=min(m2,d1);  
    if(mul(a[i],p,a[i%n+1]) && mul(a[i%n+1],a[i],p)) m2=min(m2,d2);
 }
 printf("%.10lf\n",pi*(m1*m1-m2*m2));
 return 0;
}