#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;

struct graph
{struct edge
 {	int u,v,next;
 };
 struct edge e[1000010];
 int num;
 int head[500010],pre[500010];
 void add(int u,int v)
 {	e[num].u=u;
  	e[num].v=v;
  	e[num].next=head[u];
  	if(head[u]==-1) pre[u]=num;
  	head[u]=num;
  	num++;
  	e[num].u=v;
  	e[num].v=u;
  	e[num].next=head[v];
  	if(head[v]==-1) pre[v]=num;
  	head[v]=num;
  	num++;
 }
};
struct graph g1,g2;

int n,tot;
int f[500010],d[500010],used[500010],q[1000010],fa[500010],ans[500010][4];
map<pair<int,int>,int> h;

int find(int i)
{return fa[i]==i?i:fa[i]=find(fa[i]);
}

void dfs(int i,int x)
{int j,fx,fy;
 
 j=g1.head[i];
 while(j!=-1)
 {	if(g1.e[j].v!=x)
 	{	f[g1.e[j].v]=i;
 		if((i<g1.e[j].v && h.find(make_pair(i,g1.e[j].v))!=h.end()) || (i>g1.e[j].v && h.find(make_pair(g1.e[j].v,i))!=h.end()))
 		{	fx=find(g1.e[j].v);
 			fy=find(i);
 			fa[fx]=fy;
 			g2.e[g2.pre[fy]].next=g2.head[fx];
 			g2.pre[fy]=g2.pre[fx];	
		}
 		dfs(g1.e[j].v,i);
 	}
 	j=g1.e[j].next;
 }
}

int main()
{int i,j,x,y,t=1,w=0,s,flag=1,fx,fy;
 
 scanf("%d",&n);
 memset(g1.head,-1,sizeof(g1.head));
 for(i=1;i<n;i++)
 {	scanf("%d%d",&x,&y);
 	g1.add(x,y);
 	d[x]++;
 	d[y]++;
 }
 memset(g2.head,-1,sizeof(g2.head));
 for(i=1;i<n;i++)
 {	scanf("%d%d",&x,&y);
 	if(x>y) swap(x,y);
	g2.add(x,y);
 	h[make_pair(x,y)]=1;
 }
 for(i=1;i<=n;i++) fa[i]=i;
 dfs(1,0);
 for(i=1;i<=n;i++)
 	if(i!=1 && d[i]==1) q[++w]=i;
 s=0;
 while(t<=w)
 {	x=q[t];
 	y=f[q[t]];
 	//cout<<x<<" "<<y<<endl;
 	if(x!=1 && find(x)!=find(y))
 	{	tot++;
 		ans[tot][0]=x;
 		ans[tot][1]=y;
 		fx=find(x);
 		j=g2.head[fx];
 		while(j!=-1 && find(g2.e[j].u)==find(g2.e[j].v)) j=g2.e[j].next;
 		g2.head[fx]=j;
 		ans[tot][2]=g2.e[j].u;
 		ans[tot][3]=g2.e[j].v;
 		fy=find(g2.e[j].v);
 		fa[fx]=fy;
 		g2.e[g2.pre[fy]].next=g2.head[fx];
 		g2.pre[fy]=g2.pre[fx];
 	}
 	d[f[q[t]]]--;
 	if(d[f[q[t]]]==1) q[++w]=f[q[t]];
 	t++;
 }
 printf("%d\n",tot);
 for(i=1;i<=tot;i++)
 	printf("%d %d %d %d\n",ans[i][0],ans[i][1],ans[i][2],ans[i][3]);
 return 0;
}