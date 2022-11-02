#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
const int V=100100;
struct Point{int x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    Point operator-(const Point& p)const
    {return Point(x-p.x,y-p.y);}
}p[V];
int Less(Point x,Point y)
{
    LL te=(LL)x.x*y.y-(LL)x.y*y.x;
    if(te<0)return 1;
    else if(te==0)return 0;
    else return -1;
}
int n,i,top,tail,Q,ct;
int main()
{
    while(~scanf("%d",&n))
    {
        for(i=0;i<n;i++)
        scanf("%d%d",&p[i].x,&p[i].y);
        scanf("%d",&Q);
        while(Q--)
        {
            Point tmp;
            scanf("%d%d",&tmp.x,&tmp.y);
            bool can=true;
            for(i=0;i<n;i++)
            if(-1==Less(tmp-p[(i+1)%n],p[i]-p[(i+1)%n]))
            {can=false;break;}
            if(!can){puts("0");continue;}
            LL ret=0;tail=0;
            bool C=false;
            for(top=0;top<n;top++)
            {
                while(((!C)&&top==tail)||Less(tmp-p[tail],p[top]-p[tail])==1)
                {tail++;if(tail==n){tail=0;C=true;}}
                if(!C)ct=tail-top-1;
                else ct=tail-top+n-1;
                ret+=(LL)ct*(ct-1)/2;
                if(Less(tmp-p[tail],p[top]-p[tail])!=0)ct=n-1-ct;
                else ct=n-2-ct;
                ret+=(LL)ct*(ct-1)/2;
            }
            cout<<(LL)n*(n-1)*(n-2)/6-ret/2<<endl;
        }
    }
}