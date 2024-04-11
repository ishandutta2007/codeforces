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
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
int dp[60][60][4][2];
const int V=120;
char map[V][V];
int n,M;
bool check(int x,int y)
{
    if(x<0||x>=n)return false;
    if(y<0||y>=M)return false;
    if(map[x][y]=='0')return false;
    return true;
}
int m,i,nx,ny,nd,nz,tx,ty,step;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(dp,-1,sizeof(dp));
        dp[0][0][1][0]=0;
        for(i=0;i<n;i++)
        scanf("%s",map[i]);
        M=strlen(map[0]);
        bool f=false;
        nx=0;ny=0;nd=1;nz=0;
        for(step=1;step<=m;)
        {
            while(1)
            {               
                tx=nx+dx[nd];
                ty=ny+dy[nd];
                if(check(tx,ty)&&map[tx][ty]==map[nx][ny])
                {nx=tx,ny=ty;}
                else break;
            }
            while(1)
            {
                int td;
                if(nz==0)td=(nd+3)%4;
                else td=(nd+1)%4;
                tx=nx+dx[td];
                ty=ny+dy[td];
                if(check(tx,ty)&&map[tx][ty]==map[nx][ny])
                {nx=tx,ny=ty;}
                else break;
            }
            tx=nx+dx[nd];
            ty=ny+dy[nd];
            if(check(tx,ty))
            {
                nx=tx;ny=ty;
            }
            else
            {
                if(nz==1)nd=(nd+1)%4;
                nz^=1;
            }
            if(!f&&dp[nx][ny][nd][nz]!=-1)
            {
                f=true;
                int xh=step-dp[nx][ny][nd][nz];
            //  printf("Xh : %d\n",xh);
                step=m-(m-step)%xh;
            }
            else dp[nx][ny][nd][nz]=step;
            step++;
        //  printf("%d %c %d %d\n",step,map[nx][ny],nd,nz);
        }
        printf("%c\n",map[nx][ny]);
    }
}