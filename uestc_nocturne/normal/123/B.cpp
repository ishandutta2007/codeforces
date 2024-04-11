#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef long long LL;
int AB(int x){if(x<0)return -x;return x;}
struct Point{int x,y,la,lb;}p[120];
int a,b,i,ans;
int main()
{
    while(~scanf("%d%d",&a,&b))
    {
        for(i=0;i<2;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            if(p[i].x+p[i].y>0)
            p[i].la=(p[i].x+p[i].y)/(2*a);
            else
            p[i].la=-1-(-1*(p[i].x+p[i].y)/(2*a));
            if(p[i].x-p[i].y>0)
            p[i].lb=(p[i].x-p[i].y)/(2*b);
            else
            p[i].lb=-1-(-1*(p[i].x-p[i].y)/(2*b));
    //      printf("%d %d\n",p[i].la,p[i].lb);
        }
        ans=max(AB(p[0].la-p[1].la),AB(p[0].lb-p[1].lb));
        printf("%d\n",ans);
    }
}