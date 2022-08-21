//zzq
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <map>
using namespace std;
int n,xx0,yy0;
map<int,bool> sb[400001];
int gcd(int a,int b)
{
    if(b==0) return a; else return gcd(b,a%b);
}
int main()
{
    scanf("%d%d%d",&n,&xx0,&yy0);
    int need=0;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x-=xx0; y-=yy0;
        int xx,yy;
        double slope;
        if(!x) xx=2,yy=2;
        else if(!y) xx=3,yy=3;
        else
        {
            xx=x,yy=y;
            if(xx<0&&yy<0) xx=-xx,yy=-yy;
            int gc=gcd(xx,yy);
            xx/=gc; yy/=gc;
            if(xx<0) xx=-xx,yy=-yy;
        }
        if(sb[xx][yy]) continue;
        sb[xx][yy]=1; need++;
    }
    cout<<need;
    return 0;
}