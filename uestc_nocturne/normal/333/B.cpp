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
const int V=1200;
int r[V],c[V],X,Y,x[120],y[120];
int co[10][10],n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(r,0,sizeof(r));
        memset(c,0,sizeof(c));
        memset(co,0,sizeof(co));
        co[0][2]=co[0][5]=co[0][6]=1;
        co[1][3]=co[1][4]=co[1][7]=1;
        co[2][0]=co[2][3]=co[2][7]=1;
        co[3][1]=co[3][2]=co[3][6]=1;
        co[4][1]=co[4][5]=co[4][6]=1;
        co[5][0]=co[5][4]=co[5][7]=1;
        co[6][0]=co[6][3]=co[6][4]=1;
        co[7][1]=co[7][2]=co[7][5]=1;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&X,&Y);
            if(X>1&&X<n)r[X]=1;
            if(Y>1&&Y<n)c[Y]=1;
        }
        int ret=0;
        for(int i=2;n-i+1>i;i++)
        {
            int j=n-i+1;
            x[0]=1,y[0]=i;
            x[1]=1,y[1]=j;
            x[2]=i,y[2]=1;
            x[3]=i,y[3]=n;
            x[4]=j,y[4]=1;
            x[5]=j,y[5]=n;
            x[6]=n,y[6]=i;
            x[7]=n,y[7]=j;
            int mx=0;
            for(int k=0;k<(1<<8);k++)
            {
                int ct=0;
                for(int l=0;l<8;l++)
                if(k&(1<<l))ct++;
                for(int l=0;l<8;l++)
                if((k&(1<<l))&&(r[x[l]]||c[y[l]]))ct=0;
                for(int X=0;X<8;X++)
                if(k&(1<<X))
                for(int Y=0;Y<X;Y++)
                if((k&(1<<Y))&&(co[X][Y]))
                ct=0;
                mx=max(mx,ct);
            }
            ret+=mx;
        }
        if(n%2)
        {
            if(!r[n/2+1]||!c[n/2+1])ret++;
        }
        printf("%d\n",ret);
    }
}