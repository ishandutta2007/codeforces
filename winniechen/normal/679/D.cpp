#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
#define N 405
int n,m,now;
int map[N][N],pa[N*N],pb[N*N],in1[N],b[N],vis[N][N];
double s0[N][N],s1[N][N],s2[N][N],p[N][N],a[N],tmp,ans;
vector<int>v[N];
vector<int>::iterator it;
void update(int a,int b,double x)
{
    if(a<0)return;
    if(vis[a][b]!=now)vis[a][b]=now,p[a][b]=0,v[a].push_back(b);
    p[a][b]=max(p[a][b],x);
}
int main()
{
    scanf("%d%d",&n,&m);memset(map,0x3f,sizeof(map));for(int i=1;i<=n;i++)map[i][i]=0;
    for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),pa[i]=x,pb[i]=y,in1[x]++,in1[y]++,map[x][y]=map[y][x]=1;
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int x=pa[j],y=pb[j];
            if(map[i][y]==map[i][x]+1)
                s1[i][x]+=1.0/n/in1[y],s2[i][y]+=1.0/n/in1[x];
            else if(map[i][y]==map[i][x]-1)
                s1[i][y]+=1.0/n/in1[x],s2[i][x]+=1.0/n/in1[y];
            else
                s0[i][y]+=1.0/n/in1[x],s0[i][x]+=1.0/n/in1[y];
        }
    for(int i=1;i<=n;i++)
    {
        memset(b,0,sizeof(b));memset(a,0,sizeof(a));
        for(int j=1;j<=n;j++)b[map[i][j]]++;
        for(int j=0;j<n;j++)if(b[j])a[j]=1.0/n;
        for(int j=1;j<=n;j++)
        {
            now++;
            for(int k=1;k<=n;k++)
            {
                update(map[i][k],map[j][k],s0[i][k]);
                update(map[i][k]+1,map[j][k],s1[i][k]);
                update(map[i][k]-1,map[j][k],s2[i][k]);
            }
            for(int k=0;k<=n;k++)
            {
                tmp=0;
                for(it=v[k].begin();it!=v[k].end();it++)tmp+=p[k][*it];
                v[k].clear();a[k]=max(tmp,a[k]);
            }
        }tmp=0;
        for(int j=0;j<=n;j++)tmp+=a[j];ans=max(ans,tmp);
    }printf("%.11lf\n",ans);
}