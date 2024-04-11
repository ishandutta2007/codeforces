#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<math.h>
#include<string>
#include<time.h>
#include<bitset>
#include<vector>
#include<memory>
#include<utility>
#include<stdio.h>
#include<sstream>
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
#define y1 dream
int x1,y1,r1;
int x2,y2,r2;
int x3,y3,r3;
double nowx,nowy;
double cur_ans;
inline double dist(double x1,double y1,double x2,double y2)
{
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}
double ans1,ans2,ans3;
inline double calc_ans(double x,double y)
{
    ans1=dist(x1,y1,x,y)*r2*r2*r3*r3;
    ans2=dist(x2,y2,x,y)*r3*r3*r1*r1;
    ans3=dist(x3,y3,x,y)*r1*r1*r2*r2;
    return max(max(fabs(ans1-ans2),fabs(ans2-ans3)),fabs(ans1-ans3));
}
const double eps=1e-3;
bool try_find_ans()
{
    double t=0.9;
    double size=500;
    nowx=rand()%1000;
    nowy=rand()%1000;
    double cur_ans=calc_ans(nowx,nowy);
    for (;;)
    {
        double c=rand()/(double)RAND_MAX-0.5;
        double deltax=c*size;
        if (size<1e-11) return false;
        c=rand()/(double)RAND_MAX-0.5;
        double deltay=c*size;
        double newx=nowx+deltax;
        double newy=nowy+deltay;
        double new_ans=calc_ans(newx,newy);
        if (new_ans<cur_ans)
        {
            cur_ans=new_ans;
            nowx=newx;
            nowy=newy;
            if ((ans1-ans2<eps)&&(ans2-ans3<eps)&&(ans3-ans1<eps))
            {
                return true;
            }
        }
        else
        {
            if (exp(-(new_ans-cur_ans)/t)*RAND_MAX>rand())
            {
                cur_ans=new_ans;
                nowx=newx;
                nowy=newy;
            }
            t*=0.9;
        }
        size*=0.99;
    }
    return false;
}
double min_ans;
double min_nowx;
double min_nowy;
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    scanf("%d%d%d%d%d%d%d%d%d",&x1,&y1,&r1,&x2,&y2,&r2,&x3,&y3,&r3);
    int i;
    min_ans=1e100;
    for (i=0;i<100;i++)
    {
        if (try_find_ans())
        {
            if (ans1<min_ans)
            {
                min_ans=ans1;
                min_nowx=nowx;
                min_nowy=nowy;
            }
        }
    }
    if (min_ans>1e99) return 0;
    printf("%.5lf %.5lf\n",min_nowx,min_nowy);
    return 0;
}