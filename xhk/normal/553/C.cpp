#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

struct edge
{int u,v,c,next;
};
struct edge e[200010];

int n,m,num,col,flag=1;
long long mod=1000000007,ans=0;
int p[100010],used[100010],dis[100010];

void add(int u,int v,int c)
{e[num].u=u;
 e[num].v=v;
 e[num].c=c;
 e[num].next=p[u];
 p[u]=num;
 num++;
 
 e[num].u=v;
 e[num].v=u;
 e[num].c=c;
 e[num].next=p[v];
 p[v]=num;
 num++;
}

void work(int i)
{int j;
 
 j=p[i];
 while(j!=-1)
 {  if(flag==0) return;
    if(used[e[j].v]==0)
    {   used[e[j].v]=1;
        dis[e[j].v]=dis[i]*e[j].c;
        work(e[j].v);
    }
    else if(dis[i]*e[j].c!=dis[e[j].v])
    {   flag=0;
        return;
    }
    j=e[j].next;
 }  
}

int main()
{int i,j,x,y,z; 
 
 scanf("%d%d",&n,&m);
 
 memset(p,-1,sizeof(p));
 for(i=1;i<=m;i++)
 {  scanf("%d%d%d",&x,&y,&z);
    if(z==0) z=-1;
    add(x,y,z);
 }
 
 ans=1;
 col=0;
 for(i=1;i<=n;i++)
    if(used[i]==0)
    {   dis[i]=1;
        used[i]=1;
        col++;
        if(col!=1)
        {   ans*=2;
            ans%=mod;
        }
        work(i);
        if(flag==0)
        {   cout<<0<<endl;
            return 0;
        }
    }
 
 cout<<ans<<endl;
 
 return 0;
}