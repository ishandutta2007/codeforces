/*
Author: elfness@UESTC
*/
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long LL;
const double pi=acos(-1.0);
int w,h,A;
int main()
{
    while(~scanf("%d%d%d",&w,&h,&A))
    {
        double ret=0.0;
        if(A==0||A==180)
        {
            ret=1.0*w*h;
        }
        else if(A==90)
        {
            ret=1.0*min(w,h)*min(w,h);
        }
        else
        {
            if(A>90)A=180-A;
            if(w<h)swap(w,h);
            double a=A/180.0*pi;
            double x=w/2.0;
            double y=h/2.0;
            double tx=x*cos(a)-y*sin(a);
            double ty=y*cos(a)+x*sin(a);
            double tx2=x*cos(a)+y*sin(a);
            double ty2=-y*cos(a)+x*sin(a);
            double r=(ty-y)/(ty-ty2)*(tx2-tx)+tx;
            double tx3=-x*cos(a)-y*sin(a);
            double ty3=y*cos(a)-x*sin(a);
            double l=tx-(ty-y)/(ty-ty3)*(tx-tx3);
            if(tx3<=-x)
            {
                ret=1.0*w*h;
                ret-=(l+x)*(l+x)*tan(a);
                ret-=(x-r)*(x-r)/tan(a);
            }
            else
            {
                ret=1.0*h*h/sin(a);
            }
        }
        printf("%.12f\n",ret);
    }
}