#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

struct point
{double x,y;
};
struct point a[100010];

int n,top;
int stack[100010];
double p,q,ans,inf=1e9;

bool cmp(struct point A,struct point B)
{return A.x<B.x;
}

double mul(point p0,point p1,point p2)
{return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

int main()
{int i,j,i1,i2;
 double t1,t2;
 
 scanf("%d%lf%lf",&n,&p,&q);
 for(i=1;i<=n;i++)
    scanf("%lf%lf",&a[i].x,&a[i].y);
 sort(a+1,a+n+1,cmp);   
 for(i=1;i<=n;i++)
    if(top<2)
    {   top++;
        stack[top]=i;
    }
    else
    {   while(top>=2 && mul(a[stack[top-1]],a[stack[top]],a[i])>=0) top--;
        top++;
        stack[top]=i;
    }
 ans=inf;
 for(i=1;i<=top;i++)
 {  //cout<<stack[i]<<endl;
    ans=min(ans,max(p/a[stack[i]].x,q/a[stack[i]].y));
    if(i!=top)
    {   i1=stack[i];
        i2=stack[i+1];
        if(a[i1].x<a[i2].x && a[i1].y<a[i2].y) continue;
        //cout<<a[i1].x<<" "<<a[i1].y<<" "<<a[i2].x<<" "<<a[i2].y<<endl;
        t1=(p*a[i2].y-q*a[i2].x)/(a[i1].x*a[i2].y-a[i1].y*a[i2].x);
        t2=(p-a[i1].x*t1)/a[i2].x;
        //cout<<t1<<" "<<t2<<endl;
        if(t1>0 && t2>0)
            ans=min(ans,t1+t2);
    }
 }
 printf("%.10lf\n",ans);
 
 return 0;
}