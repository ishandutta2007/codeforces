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
const int V=1020;
char map[V][V];
struct Node{int x,y;}q[V*V],qz[V*V];
int ct[V*V],d[V*V],zn,on,n,m;
int vz[V][V],vo[V][V];
int dx[]={1,-1,0,0,1,1,-1,-1};
int dy[]={0,0,1,-1,-1,1,-1,1};
int set[V*V];
int find(int x)
{
    if(x!=set[x])set[x]=find(set[x]);
    return set[x];
}
bool fill(int x,int y)
{
//  printf("%d %d\n",x,y);
    vz[x][y]=1;
    qz[zn].x=x;
    qz[zn++].y=y;
    for(int i=0;i<8;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=n)return false;
        if(ty<0||ty>=m)return false;
        if(map[tx][ty]=='1')continue;
        if(vz[tx][ty]==2)return false;
        if(vz[tx][ty]==0)
        {
            if(!fill(tx,ty))return false;
        }
    }
    return true;
}
int doit(int x,int y)
{
    zn=0;on=0;
    int i,j,tx,ty;
    if(!fill(x,y))
    {
        for(i=0;i<zn;i++)
        vz[qz[i].x][qz[i].y]=2;
        return 0;
    }
//  printf("doit : %d %d\n",x,y);
    for(i=0;i<zn;i++)
    {
        for(j=0;j<8;j++)
        {
            tx=qz[i].x+dx[j];
            ty=qz[i].y+dy[j];
            if(map[tx][ty]=='1'&&vo[tx][ty]==-1)
            {
                vo[tx][ty]=on;
                d[on]=0;
                q[on].x=tx;
                q[on++].y=ty;
            }
        }
    }
    for(i=0;i<on;i++)set[i]=i;
    for(i=0;i<on;i++)
    {
        for(j=0;j<4;j++)
        {
            tx=q[i].x+dx[j];
            ty=q[i].y+dy[j];
            if(tx<0||tx>=n)continue;
            if(ty<0||ty>=m)continue;
            if(map[tx][ty]=='1'&&vo[tx][ty]!=-1)
            {
                d[i]++;
                if(find(i)!=find(vo[tx][ty]))
                set[find(i)]=vo[tx][ty];
            }
        }
    }
    bool can=true;
    for(i=0;i<on;i++)if(d[i]!=2){can=false;break;}
    for(i=0;i<on;i++)if(find(i)!=find(0)){can=false;break;}
//  for(i=0;i<on;i++)printf("%d %d %d\n",q[i].x,q[i].y,d[i]);
    for(i=0;i<zn;i++)vz[qz[i].x][qz[i].y]=2;
    for(i=0;i<on;i++)vo[q[i].x][q[i].y]=-1;
    if(can)return on;
    return 0;
}
int i,j,ret;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        ret=0;
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        memset(vz,0,sizeof(vz));
        memset(vo,-1,sizeof(vo));
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        if(map[i][j]=='0'&&vz[i][j]==0)
        ret=max(ret,doit(i,j));
        for(i=0;i+1<n;i++)
        {
            int te=0;
            for(j=0;j<m;j++)
            {
                if(map[i][j]=='1'&&'1'==map[i+1][j])
                {te++;if(te>1)ret=max(ret,4);}
                else te=0;
            }
        }
        
        for(j=0;j+1<m;j++)
        {
            int te=0;
            for(i=0;i<n;i++)
            {
                if(map[i][j]=='1'&&'1'==map[i][j+1])
                {te++;if(te>1)ret=max(ret,4);}
                else te=0;
            }
        }
        printf("%d\n",ret);
    }
}