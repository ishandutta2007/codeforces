#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

struct edge
{int u,v,f,next;
};
struct edge e[200010];

int n,m,s,num,maxflow,inf=1e9;
int a[1010][3],head[110],dis[110],gap[110],pre[110],mf[110],p1[110];
long double ans,eps=1e-12;

void add(int u,int v,int f)
{e[num].u=u;
 e[num].v=v;
 e[num].f=f;
 e[num].next=head[u];
 head[u]=num;
 num++;
 e[num].u=v;
 e[num].v=u;
 e[num].f=0;
 e[num].next=head[v];
 head[v]=num;
 num++;
}

void change(int T)
{int j;
 j=pre[T];
 while(j!=-1)
 {	e[j].f-=mf[T];
 	e[j^1].f+=mf[T];
 	j=pre[e[j].u];
 }
}

void sap(int S,int T,int N)
{int i,j,md,me,flag;
 
 memset(pre,-1,sizeof(pre));
 memset(dis,0,sizeof(dis));
 memset(gap,0,sizeof(gap));
 gap[0]=N;
 mf[S]=inf;
 for(i=1;i<=N;i++) p1[i]=head[i];
 i=S;
 while(dis[i]<=N)
 {	j=p1[i];
 	flag=0;
 	while(j!=-1)
 	{	if(e[j].f>0 && dis[e[j].v]==dis[i]-1)
 		{	p1[i]=j;
 			pre[e[j].v]=j;
 			mf[e[j].v]=min(mf[i],e[j].f);
 			i=e[j].v;
 			flag=1;
			if(i==T)
 			{	change(T);
 				maxflow+=mf[T];
 				i=S;
 			}
 			break;
 		}
 		j=e[j].next;
 	}
 	if(!flag)
 	{	md=N+1;
 		me=0;
 		j=head[i];
 		while(j!=-1)
 		{	if(e[j].f>0 && dis[e[j].v]<md)
 			{	md=dis[e[j].v];
 				me=j;
 			}
 			j=e[j].next;
 		}
 		gap[dis[i]]--;
 		if(gap[dis[i]]==0) return;
 		dis[i]=md+1;
 		gap[dis[i]]++;
 		p1[i]=me;
 		if(i!=S) i=e[pre[i]].u;
 	}
 }
}

int main()
{int i,j,x;
 long double l,r,mid;
 
 scanf("%d%d%d",&n,&m,&s);
 for(i=1;i<=m;i++)
 	scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
 l=0;
 r=(long double)1000000*m/n;
 while(r-l>eps)
 {	mid=(l+r)/2;
 	memset(head,-1,sizeof(head));
 	num=0;
 	add(1,1+1,s);
 	for(i=1;i<=m;i++)
 	{	if((long double)a[i][2]/mid>s)	
 			x=s;
 		else
		 	x=a[i][2]/mid;
		add(1+a[i][0],1+a[i][1],x);
	}
 	add(1+n,1+n+1,s);	
 	maxflow=0;
	sap(1,1+n+1,1+n+1);
	if(maxflow==s)
	{	ans=max(ans,mid);
		l=mid;
	}
	else
		r=mid;
 }
 printf("%.10lf\n",(double)(ans*s));
 return 0;
}