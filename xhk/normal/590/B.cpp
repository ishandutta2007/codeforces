#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;

double v,t,xx1,yy1,xx2,yy2,tx,ty,wx,wy;
double ans,eps=1e-10;

int check(double t1,double x,double y)
{double d;
 d=x*x+y*y;
 if(v*t1*v*t1>=d)
    return 1;
 else
    return 0;
}

int main()
{int i,j;
 double mid,l,r;
  
 scanf("%lf%lf%lf%lf",&xx1,&yy1,&xx2,&yy2);
 xx2-=xx1;
 yy2-=yy1;
 
 scanf("%lf%lf",&v,&t);
 
 scanf("%lf%lf%lf%lf",&tx,&ty,&wx,&wy);
 
 l=0;
 r=80000000;
 ans=80000000;
 while(fabs(r-l)>eps)
 {  mid=(l+r)/2;
    if(check(mid,xx2-mid*tx,yy2-mid*ty))
    {   ans=min(ans,mid);
        r=mid;
    }
    else
        l=mid;
 }
 
 if(ans<=t && check(ans,xx2-min(t,mid)*tx,yy2-min(t,mid)*ty))
 {  printf("%.15lf\n",ans);
    return 0;
 }
 
 xx2-=t*tx;
 yy2-=t*ty;
 //cout<<xx2<<" "<<yy2<<endl;

 l=0;
 r=80000000;
 ans=80000000;
 
 while(fabs(r-l)>eps)
 {  //cout<<l<<" "<<r<<endl;
    mid=(l+r)/2;
    if(check(t+mid,xx2-mid*wx,yy2-mid*wy))
    {   ans=min(ans,t+mid);
        r=mid;
    }
    else
        l=mid;
 }
 
 printf("%.15lf\n",ans);
 
 return 0;
}
/*
0 0 10000 10000
1 1000
-10000 -10000
-10000 -10000
*/