#include<iostream>
#include<cstdio>
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
struct bbian
{
	int u,v,nex;
}a[8000004];
int head[2000004],tmp;
void addb(int x,int y)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int dfn[2000004],low[2000004],cnt;
bool vis[2000004];
int sta[2000004],ttop;
int cid;
int col[2000004];
void tarjan(int x)
{
	dfn[x]=low[x]=++cnt;
	vis[x]=true;
	sta[++ttop]=x;
	for(int i=head[x];i;i=a[i].nex)
	{
		if(dfn[a[i].v]==0)
		{
			tarjan(a[i].v);
			low[x]=min(low[x],low[a[i].v]);
		}
		else if(vis[a[i].v]==true)low[x]=min(low[x],dfn[a[i].v]);
	}
	if(low[x]==dfn[x])
	{
		//printf("!!!\n");
		++cid;
		while(ttop>=1)
		{
			col[sta[ttop]]=cid;
			vis[sta[ttop]]=false;
			if(sta[ttop]==x)
			{
				ttop--;
				break;
			}
			ttop--;
		}
	}
}
int ist[1005];
int main()
{
	int t,n,m,k,zs,opt,x,y,z;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		k=read();
		zs=n*k;
		tmp=0;
		for(int i=1;i<=2*zs;i++)
		{
			head[i]=0;
			dfn[i]=low[i]=0;
			vis[i]=false;
			col[i]=0;
		}
		cnt=0;
		ttop=0;
		cid=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=k-1;j++)
			{
				addb((i-1)*k+j,(i-1)*k+j+1);
				addb((i-1)*k+j+1+zs,(i-1)*k+j+zs);
			}
			addb(i*k+zs,i*k);
			if(i<=n-1)
			{
				for(int j=1;j<=k;j++)
				{
					addb((i)*k+j,(i-1)*k+j);
					addb((i-1)*k+j+zs,i*k+j+zs);
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			opt=read();
			if(opt==1)
			{
				x=read();
				y=read();
				if(y>1)
				{
					addb((x-1)*k+y,(x-1)*k+y-1);
					addb((x-1)*k+y-1+zs,(x-1)*k+y+zs);
				}
				else
				{
					addb((x-1)*k+1,(x-1)*k+1+zs);
				}
			}
			else if(opt==2)
			{
				x=read();
				y=read();
				z=read();
				for(int i=1;i<=min(k,z-2);i++)
				{
					if(z-1-i>k)
					{
						continue;
					}
					addb((x-1)*k+i+zs,(y-1)*k+z-1-i);
					addb((y-1)*k+z-1-i+zs,(x-1)*k+i);
					//printf("orz!%d %d\n",(x-1)*k+i+zs,(y-1)*k+z-1-i);
					//printf("orz!%d %d\n",(y-1)*k+z-1-i+zs,(x-1)*k+i);
				}
				if(z-1<=k)
				{
					addb((x-1)*k+z-1+zs,(x-1)*k+z-1);
					addb((y-1)*k+z-1+zs,(y-1)*k+z-1);
				}
			}
			else
			{
				x=read();
				y=read();
				z=read();
				for(int i=1;i<=min(k,z-2);i++)
				{
					if(z-1-i>k)
					{
						addb((x-1)*k+i,(x-1)*k+i+zs);
						continue;
					}
					//printf("orz%d %d\n",(x-1)*k+i,(y-1)*k+z-1-i+zs);
					//printf("orz%d %d\n",(y-1)*k+z-1-i,(x-1)*k+i+zs);
					addb((x-1)*k+i,(y-1)*k+z-i-1+zs);
					addb((y-1)*k+z-i-1,(x-1)*k+i+zs);
				}
			}
		}
		for(int i=1;i<=2*zs;i++)if(dfn[i]==0)tarjan(i);
		bool flag=true;
		//for(int i=1;i<=2*zs;i++)printf("%d %d\n",i,col[i]);
		//printf("\n");
		//ist[1]=ist[2]=ist[3]=ist[4]=ist[5]=ist[10]=ist[15]=ist[20]=1;
		//for(int i=21;i<=40;i++)ist[i]=1-ist[i-20];
		//for(int i=1;i<=tmp;i++)if(ist[a[i].u]==1&&ist[a[i].v]==0)printf("%d %d\n",a[i].u,a[i].v);
		for(int i=1;i<=zs;i++)
		{
			if(col[i]==col[i+zs])
			{
				flag=false;
				break;
			}
		}
		if(flag==false)
		{
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++)
		{
			int now=0;
			for(int j=1;j<=k;j++)
			{
				if(col[(i-1)*k+j]<col[(i-1)*k+j+zs])
				{
					now=j;
					break;
				}
			}
			printf("%d ",now);
		}
		printf("\n");
	}
	return 0;
}