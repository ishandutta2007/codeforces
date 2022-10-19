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
int sl[200015],a[200015];
bool vis[200015];
int ans[200015],cnt;
int main()
{
	int t,n,x,sth,gre;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=0;i<=n;i++)sl[i]=0,vis[i]=false;
		for(int i=1;i<=n;i++)a[i]=read(),sl[a[i]]++;
		x=0;
		while(sl[x]!=0)x++;
		//printf("%d\n",x); 
		if(x==0)
		{
			printf("%d\n",n);
			for(int i=1;i<=n;i++)printf("0 ");
			printf("\n");
			continue;
		}
		sth=0;
		gre=1;
		cnt=1;
		ans[1]=x;
		while(gre<=n)
		{
			//printf("%d %d\n",gre,x);
			sl[a[gre]]--;
			if(a[gre]<=x&&vis[a[gre]]==false)
			{
				vis[a[gre]]=true;
				sth++;
			}
			if(sth==x)
			{
				if(gre==n)break;
				for(int i=0;i<=x;i++)vis[i]=false;
				x=0;
				while(sl[x]>0)x++;
				//printf("nex%d\n",x);
				sth=0;
				if(x==0)
				{
					for(int i=1;i<=n-gre;i++)ans[++cnt]=0;
					break;
				}
				ans[++cnt]=x;
			}
			gre++;
		}
		printf("%d\n",cnt);
		for(int i=1;i<=cnt;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}