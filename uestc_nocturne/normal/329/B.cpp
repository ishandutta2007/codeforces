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
char s[V][V];
int d[V][V];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int q[V*V],n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        scanf("%s",s[i]);
        int sx,sy;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(s[i][j]=='E')
        {sx=i;sy=j;}
        memset(d,-1,sizeof(d));
        int top=0,tail=1;
        d[sx][sy]=0;q[1]=sx*m+sy;
        while(top!=tail)
        {
            top++;
            int nx=q[top]/m;
            int ny=q[top]%m;
            //printf("%d %d\n",nx,ny);
            for(int i=0;i<4;i++)
            {
                int tx=nx+dx[i];
                int ty=ny+dy[i];
                if(tx<0||tx>=n)continue;
                if(ty<0||ty>=m)continue;
                if(s[tx][ty]=='T')continue;
                if(d[tx][ty]==-1)
                {
                    d[tx][ty]=d[nx][ny]+1;
                    tail++;
                    q[tail]=tx*m+ty;
                }
            }
        }
        int ret=0,dis=-1;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(s[i][j]=='S')
        dis=d[i][j];
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(d[i][j]!=-1&&d[i][j]<=dis&&s[i][j]>='0'&&s[i][j]<='9')
        ret+=s[i][j]-'0';
        printf("%d\n",ret);
    }
}