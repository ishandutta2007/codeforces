#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
int fa[300001],ans[300001];
int dis[300001];
bool vis[300001];
queue<int>que;
int findf(int n)
{
    if(fa[n]==n)return n;
    else return fa[n]=findf(fa[n]);
}
struct bbian
{
    int u,v,nex;
}a[600001];
int head[300001],tmp;
int maxn,maxp;
void addb(int x,int y)
{
    a[++tmp].u=x;
    a[tmp].v=y;
    a[tmp].nex=head[x];
    head[x]=tmp;
}
void bfs(int x)
{
    //printf("bfs:%d\n",x);
    que.push(x);
    dis[x]=0;
    vis[x]=1;
    maxn=0;
    maxp=x;
    int sth;
    while(!que.empty())
    {
        sth=que.front();
        //printf("dis:%d %d\n",sth,dis[sth]);
        if(dis[sth]>maxn)
        {
            maxn=dis[sth];
            maxp=sth;
        }
        que.pop();
        for(int i=head[sth];i;i=a[i].nex)
        {
            if(vis[a[i].v])continue;
            dis[a[i].v]=dis[sth]+1;
            vis[a[i].v]=true;
            que.push(a[i].v);
        }
    }
    //printf("bfsend\n");
}
void csh(int x)
{
     que.push(x);
     dis[x]=0;
     vis[x]=0;
     int sth;
     while(!que.empty())
     {
     	 sth=que.front();
     	 que.pop();
     	 for(int i=head[sth];i;i=a[i].nex)
     	 {
     	    if(!vis[a[i].v])continue;
     	    dis[a[i].v]=0;
     	    vis[a[i].v]=0;
     	    que.push(a[i].v);
     	}
     }
}
int main()
{
    int n,m,q,opt,x,y;
    n=read();
    m=read();
    q=read();
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        x=read();
        y=read();
        addb(x,y);
        addb(y,x);
        x=findf(x);
        y=findf(y);
        fa[x]=y;
    }
    for(int i=1;i<=n;i++)
    {
        if(!ans[findf(i)])
        {
            bfs(i);
            csh(i);
            bfs(maxp);
            ans[findf(i)]=maxn;
        }
    }
    for(int i=1;i<=q;i++)
    {
    	opt=read();
    	if(opt==1)
    	{
    		x=read();
    		printf("%d\n",ans[findf(x)]);
    	}
    	else
    	{
    		x=read();
    		y=read();
    		x=findf(x);
    		y=findf(y);
    		if(x==y)continue;
    		ans[y]=max(ans[x],max(ans[y],(ans[x]+1)/2+(ans[y]+1)/2+1));
    		ans[x]=0;
    		fa[x]=y;
    	}
    }
    return 0;
}