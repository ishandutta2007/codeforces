#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 LL;
const int V=1200;
const int En=12000;
const LL ooo=100000000;
const LL oo=ooo*ooo;
struct Edge
{
	int num,ne;
	LL len;
}e[En];
int p[V],K;
void add(int x,int y,LL z)
{
	e[K].num=y;e[K].len=z;
	e[K].ne=p[x];p[x]=K++;
}
int q[V],n,vis[V];
LL dis[V][V];
void spfa(int S)
{
	int i,j,k,top,tail;
	for(i=0;i<n;i++)
	{
		vis[i]=0;
		dis[S][i]=oo;
	}
	top=0;tail=1;q[1]=S;
	vis[S]=1;dis[S][S]=0;
	while(top!=tail)
	{
		top=(top+1)%V;
		i=q[top];vis[i]=0;
		for(j=p[i];j!=-1;j=e[j].ne)
		{
			k=e[j].num;
			if(dis[S][k]-e[j].len>dis[S][i])
			{
				dis[S][k]=dis[S][i]+e[j].len;
				if(!vis[k])
				{
					vis[k]=1;
					tail=(tail+1)%V;
					q[tail]=k;
				}
			}
		}
	}
}
LL D[V],co[V],ma[V],z;
int m,i,j,id,x,y,S,T;
int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		scanf("%d%d",&S,&T);S--;T--;
		for(i=0;i<n;i++)p[i]=-1;K=0;
		for(i=0;i<m;i++)
		{
			scanf("%d%d%I64d",&x,&y,&z);x--;y--;
			add(x,y,z);add(y,x,z);
		}
		for(i=0;i<n;i++)cin>>ma[i]>>co[i];
		for(i=0;i<n;i++)spfa(i);
	//	for(i=0;i<n;i++){for(j=0;j<n;j++)cout<<dis[i][j]<<" ";puts("");}
		memset(vis,0,sizeof(vis));
		for(i=0;i<n;i++)D[i]=oo;
		D[S]=0;
		for(i=0;i<n;i++)
		{
			id=-1;
			for(j=0;j<n;j++)
			{
				if(!vis[j]&&(id==-1||D[id]>D[j]))
				id=j;
			}
			vis[id]=1;
			if(id==T)break;
			for(j=0;j<n;j++)
			{
				if(dis[id][j]<=ma[id])
				{
					if(D[j]-co[id]>D[id])
					D[j]=D[id]+co[id];
				}
			}
		}
		if(D[T]==oo)cout<<-1<<endl;
		else cout<<D[T]<<endl;
	}
}