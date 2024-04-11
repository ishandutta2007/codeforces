#include<bits/stdc++.h>
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
vector<int>v[400005];
int dis[400005],zy[400005];
vector<int>ky[400005];
char s[400005];
int n,m;
struct bbian
{
	int u,v,w,nex;
}a[1600004];
int head[400005],tmp;
void addb(int x,int y,int z)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].w=z;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int que[1600005],ql,qr;
void finddis(int x)
{
	if(x==0)return;
	v[(x-1)/m+1][(x-1)%m+1]=1;
	finddis(zy[x]);
}
signed main()
{
	int t;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			v[i].clear();
			v[i].push_back(0);
			for(int j=1;j<=m;j++)
			{
				if(s[j]=='#')v[i].push_back(1);
				else v[i].push_back(0);
			}
		}
		for(int i=1;i<=n;i++)ky[i].clear();
		for(int i=1;i<=n;i++)
		{
			ky[i].push_back(0);
			for(int j=1;j<=m;j++)
			{
				if(v[i][j]==0)
				{
					if(i>=2&&v[i-1][j]==1)
					{
						ky[i].push_back(0);
						continue;
					}
					if(i<=n-1&&v[i+1][j]==1)
					{
						ky[i].push_back(0);
						continue;
					}
					if(j>=2&&v[i][j-1]==1)
					{
						ky[i].push_back(0);
						continue;
					}
					if(j<=m-1&&v[i][j+1]==1)
					{
						ky[i].push_back(0);
						continue;
					}
				}
				ky[i].push_back(1);
			}
		}
		tmp=0;
		for(int i=1;i<=n*m;i++)head[i]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ky[i][j]==0)continue;
				if(i<=n-1&&j<=m-1&&ky[i+1][j+1]==1)
				{
					addb((i-1)*m+j,(i)*m+j+1,1-v[i+1][j+1]);
				}
				if(i<=n-1&&j>=2&&ky[i+1][j-1]==1)
				{
					addb((i-1)*m+j,(i)*m+j-1,1-v[i+1][j-1]);
				}
				if(i>=2&&j<=m-1&&ky[i-1][j+1]==1)
				{
					addb((i-1)*m+j,(i-2)*m+j+1,1-v[i-1][j+1]);
				}
				if(i>=2&&j>=2&&ky[i-1][j-1]==1)
				{
					addb((i-1)*m+j,(i-2)*m+j-1,1-v[i-1][j-1]);
				}
			}
		}
		for(int i=1;i<=n*m;i++)dis[i]=1000000000,zy[i]=0;
		ql=2*n*m+1;
		qr=2*n*m;
		for(int i=1;i<=n;i++)
		{
			if(ky[i][1]==true)
			{
				if(v[i][1]==1)
				{
					que[--ql]=(i-1)*m+1;
					dis[(i-1)*m+1]=0;
				}
				else
				{
					que[++qr]=(i-1)*m+1;
					dis[(i-1)*m+1]=1;
				}
			}
		}
		while(ql<=qr)
		{
			int x=que[ql];
			ql++;
			for(int i=head[x];i;i=a[i].nex)
			{
				if(dis[a[i].v]>dis[x]+a[i].w)
				{
					dis[a[i].v]=dis[x]+a[i].w;
					zy[a[i].v]=x;
					if(a[i].w==0)que[--ql]=a[i].v;
					else que[++qr]=a[i].v;
				}
			}
		}
		int minn=1000000000,mpos=0;
		for(int i=1;i<=n;i++)
		{
			if(ky[i][m]==true)
			{
				if(dis[i*m]<minn)
				{
					minn=dis[i*m];
					mpos=i;
				}
			}
		}
		//printf("%d %d\n",minn,mpos);
		if(minn==1000000000)
		{
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		finddis(mpos*m);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(v[i][j]==1)printf("#");
				else printf(".");
			}
			printf("\n");
		}
	}
}