#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[100005];
bool vis[100005];
int b[25],cnt;
int findsl(int x,int k)
{
	int ans=0;
	//printf("vis:%d %d\n",x,k);
	while(x%k==0)
	{
		ans++;
		x/=k;
	}
	return ans;
}
int main()
{
	int n,x;
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	for(int i=1;i<=2;i++)
	{
		x=1;
		while(x<=n&&vis[x]==true)x++;
		if(x==n+1)break;
		int ta=a[x];
		vis[x]=true;
		int ncnt=cnt;
		for(int sth=2;1LL*sth*sth<=ta;sth++)
		{
			if(ta%sth!=0)continue;
			while(ta%sth==0)ta/=sth;
			int minn=1000000000,mpos=0;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==true)continue;
				if(findsl(a[j],sth)<minn)
				{
					minn=findsl(a[j],sth);
					mpos=j;
				}
			}
			//printf("%d %d\n",sth,mpos);
			if(mpos==0)continue;
			bool flag=true;
			for(int j=ncnt+1;j<=cnt;j++)if(minn>=findsl(a[b[j]],sth))
			{
				flag=false;
				break;
			}
			if(flag==false)continue;
			b[++cnt]=mpos;
			vis[mpos]=true;
		}
		if(ta>1)
		{
			int minn=1000000000,mpos=0;
			for(int j=1;j<=n;j++)
			{
				if(vis[j]==true)continue;
				if(findsl(a[j],ta)<minn)
				{
					minn=findsl(a[j],ta);
					mpos=j;
				}
			}
			bool flag=true;
			for(int j=ncnt+1;j<=cnt;j++)if(minn>=findsl(a[b[j]],ta))
			{
				flag=false;
				break;
			}
			if(mpos!=0&&flag==true)
			{
				b[++cnt]=mpos;
				vis[mpos]=true;
			}
		}
		if(cnt<=ncnt+6)b[++cnt]=x;
		else vis[x]=false;
	}
	//printf("%d\n",cnt);
	//for(int i=1;i<=cnt;i++)printf("%d ",b[i]);
	//printf("\n");
	//return 0;
	sort(b+1,b+cnt+1);
	int zsl=0;
	for(int i=1;i<(1<<cnt);i++)
	{
		int bs=__builtin_popcount(i);
		int tsl=bs-2;
		if(bs%2==1)tsl=-tsl;
		if(tsl==0)continue;
		if(tsl>0)zsl+=tsl;
		else zsl-=tsl; 
	}
	printf("%d\n",zsl);
	//printf("orz\n");
	for(int i=1;i<(1<<cnt);i++)
	{
		int bs=__builtin_popcount(i);
		int tsl=bs-2;
		if(bs%2==1)tsl=-tsl;
		if(tsl==0)continue;
		if(tsl>0)
		{
			for(int j=1;j<=tsl;j++)
			{
				printf("0 %d ",bs);
				for(int k=1;k<=cnt;k++)
				{
					if(i&(1<<(k-1)))printf("%d ",b[k]);
				}
				printf("\n");
			}
		}
		else
		{
			for(int j=1;j<=-tsl;j++)
			{
				printf("1 %d ",bs);
				for(int k=1;k<=cnt;k++)
				{
					if(i&(1<<(k-1)))printf("%d ",b[k]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}