#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;

struct unit
{int x,y;
};
struct unit q[2000010];

int n,m,ans,inf=1e8;
int dis[5][5],v[6][2],f[5][1010][1010];
char a[1010][1010];

void work(int k)
{int i,j,x,y,t=1,w=0;
 
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {   f[k][i][j]=inf;
        //cout<<i<<" "<<j<<" "<<(int)a[i][j]<<" "<<k<<endl;
        if(a[i][j]==48+k)
        {   f[k][i][j]=0;
            w++;
            q[w].x=i;
            q[w].y=j;
        }
    }
 
 //cout<<w<<endl;
 
 while(t<=w)
 {  for(i=1;i<=4;i++)
    {   x=q[t].x+v[i][1];
        y=q[t].y+v[i][2];
        if(x>=1 && x<=n && y>=1 && y<=m && f[k][x][y]==inf && a[x][y]!='#')
        {   f[k][x][y]=f[k][q[t].x][q[t].y]+1;
            w++;
            q[w].x=x;
            q[w].y=y;
        }
    }
    t++;
 }

 for(i=1;i<=3;i++)
    dis[k][i]=inf;
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i][j]>48 && a[i][i]<=51)
            dis[k][a[i][j]-48]=min(dis[k][a[i][j]-48],f[k][i][j]);
}
 
int main()
{int i,j;
 
 v[1][1]=0;
 v[1][2]=1;
 v[2][1]=1;
 v[2][2]=0;
 v[3][1]=0;
 v[3][2]=-1;
 v[4][1]=-1;
 v[4][2]=0;
 
 scanf("%d%d",&n,&m);
 
 for(i=1;i<=n;i++)
 {  scanf("%s",a[i]);
    for(j=m;j>=1;j--)
        a[i][j]=a[i][j-1];
    a[i][0]='#';
 }
 
 /*
 for(i=1;i<=n;i++)
 {  for(j=1;j<=m;j++)
        cout<<a[i][j];
    cout<<endl;
 }
 return 0;
 */
 
 work(1);
 work(2);
 work(3);

 //cout<<dis[1][1]<<" "<<dis[1][2]<<" "<<dis[1][3]<<endl;

 ans=inf;
 ans=min(ans,min(dis[1][2]+dis[1][3]-2,min(dis[2][1]+dis[2][3]-2,dis[3][1]+dis[3][2]-2)));  
 ans=min(ans,dis[1][2]+dis[2][3]+dis[3][1]-3);
 
 for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
        if(a[i][j]=='.')
            ans=min(ans,f[1][i][j]+f[2][i][j]+f[3][i][j]-2);
 
 if(ans<1000000)
    cout<<ans<<endl;
 else
    cout<<-1<<endl;
 
 
 return 0;
}