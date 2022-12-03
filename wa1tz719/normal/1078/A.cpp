#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
double ans=1000000000000.0;
void update_ans(double x)
{
    ans=min(ans,x);
}
double dist(double x,double y,double xx,double yy)
{
    return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    update_ans(((double)abs(x2-x1)+abs(y2-y1)));
    //(x1,y1) to (x1,y)
    double y3;
    if (b!=0)
    {
        y3=(double)(-(double)a*x1-c)/b;
    }
    else
    {
        y3=1e20;
    }
    double y4;
    if (b!=0)
    {
        y4=(double)(-(double)a*x2-c)/b;
    }
    else
    {
        y4=1e20;
    }
    double x3;
    if (a!=0)
    {
        x3=(double)(-(double)b*y1-c)/a;
    }
    else
    {
        x3=1e20;
    }
    double x4;
    if (a!=0)
    {
        x4=(double)(-(double)b*y2-c)/a;
    }
    else
    {
        x4=1e20;
    }
    update_ans(fabs(y1-y3)+fabs(y2-y4)+dist(x1,y3,x2,y4));
    update_ans(fabs(y1-y3)+fabs(x2-x4)+dist(x1,y3,x4,y2));
    update_ans(fabs(x1-x3)+fabs(y2-y4)+dist(x3,y1,x2,y4));
    update_ans(fabs(x1-x3)+fabs(x2-x4)+dist(x3,y1,x4,y2));
    printf("%.12lf\n",ans);
    return 0;
}