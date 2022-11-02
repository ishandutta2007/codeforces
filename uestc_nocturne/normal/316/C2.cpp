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
const int V=3200;
const int En=21000;
const int oo=1000000000;
struct Edge{int num,ne,w;}e[En];
int p[V],K;
void add(int x,int y,int z)
{
    e[K].num=y;e[K].w=z;
    e[K].ne=p[x];p[x]=K++;
}
bool sx[V],sy[V];
int lx[V],ly[V],mat[V];
bool path(int u)
{
    sx[u]=true;
    for(int i=p[u];i!=-1;i=e[i].ne)
    {
        int v=e[i].num;
        if(!sy[v]&&lx[u]+ly[v]==e[i].w)
        {
            sy[v]=true;
            if(mat[v]==-1||path(mat[v]))
            {mat[v]=u;return true;}
        }
    }
    return false;
}
int N;
int KM()
{
    int i,j;
    for(i=0;i<N;i++)
    {
        lx[i]=-oo;
        for(j=p[i];j!=-1;j=e[j].ne)
        lx[i]=max(lx[i],e[j].w);
    }
    for(i=0;i<N;i++)ly[i]=0,mat[i]=-1;
    for(int u=0;u<N;u++)
    while(1)
    {
        for(i=0;i<N;i++)sx[i]=0,sy[i]=0;
        if(path(u))break;
        int dx=oo;
        for(i=0;i<N;i++)if(sx[i])
        for(j=p[i];j!=-1;j=e[j].ne)
        if(!sy[e[j].num])
        dx=min(dx,lx[i]+ly[e[j].num]-e[j].w);
        if(dx==oo)return -1;
        for(i=0;i<N;i++)if(sx[i])lx[i]-=dx;
        for(i=0;i<N;i++)if(sy[i])ly[i]+=dx;
    }
    int ret=0;
    for(i=0;i<N;i++)ret+=lx[i]+ly[i];
    return ret;
}
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int a[120][120],id[120][120],n,m;
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        scanf("%d",&a[i][j]);
        N=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(i%2==j%2)id[i][j]=N++;
        N=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(i%2!=j%2)id[i][j]=N++;
        for(int i=0;i<N;i++)p[i]=-1;K=0;
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(i%2==j%2)
        {
            int u=id[i][j];
            for(int k=0;k<4;k++)
            {
                int tx=i+dx[k];
                int ty=j+dy[k];
                if(tx<0||tx>=n)continue;
                if(ty<0||ty>=m)continue;
                int v=id[tx][ty];
                if(a[i][j]==a[tx][ty])add(u,v,2);
                else add(u,v,1);
            }
        }
        printf("%d\n",n*m-KM());
    }
}