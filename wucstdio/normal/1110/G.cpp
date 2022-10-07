#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct Edge
{
	int to;
	int next;
}e[2000005];
int t,n,edgenum,head[1000005],d[1000005],num[1000005];
void add(int u,int v)
{
	e[++edgenum].to=v;
	e[edgenum].next=head[u];
	head[u]=edgenum;
}
inline bool read()
{
	char c=getchar();
	while(c!='N'&&c!='W')c=getchar();
	return c=='W';
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n+9;i++)
		  d[i]=num[i]=head[i]=0;
		bool flag=0;
		edgenum=0;
		for(int i=1;i<n;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			num[d[u]]--,num[d[v]]--;
			d[u]++,d[v]++;
			num[d[u]]++,num[d[v]]++;
			if(d[u]>=4||d[v]>=4)flag=1;
			if(num[3]>=3)flag=1;
		}
		int x=n;
		for(int i=1;i<=x;i++)
		{
			if(read()&&!flag)
			{
				add(i,++n);
				add(n,i);
				num[d[i]]--,num[d[n]]--;
				d[i]++,d[n]++;
				num[d[i]]++,num[d[n]]++;
				add(n,++n);
				add(n,n-1);
				num[d[n]]--,num[d[n-1]]--;
				d[n]++,d[n-1]++;
				num[d[n]]++,num[d[n-1]]++;
				add(n-1,++n);
				add(n,n-2);
				num[d[n]]--,num[d[n-2]]--;
				d[n]++,d[n-2]++;
				num[d[n]]++,num[d[n-2]]++;
				if(d[i]>=4||d[n-2]>=4||d[n-1]>=4||d[n]>=4)flag=1;
				if(num[3]>=3)flag=1;
			}
		}
		int xx=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]==3)
			{
				int x=0;
				for(int hd=head[i];hd;hd=e[hd].next)
				{
					int to=e[hd].to;
					if(d[to]>1)x++;
				}
				if(x>=2)flag=1;
				if(x==1)xx++;
			}
		}
		if(xx==2)
		{
			if(num[2]&1)flag=1;
		}
		if(flag)printf("White\n");
		else printf("Draw\n");
	}
	return 0;
}