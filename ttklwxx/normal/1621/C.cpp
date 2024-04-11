#include<iostream>
#include<cstdio>
#include<vector>
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
int vis[200005],p[200005],xh[200005];
int ans[200005];
vector<int>v[200005];
vector<int>ys[200005];
int main()
{
	int t,n,k,x,cs=0,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		cs=0;
		for(int i=1;i<=n;i++)vis[i]=0,xh[i]=0,p[i]=0,ans[i]=0,v[i].clear(),ys[i].clear();
		for(int i=1;i<=n;i++)
		{
			if(ans[i]!=0)continue;
			printf("? %d\n",i);
			fflush(stdout);
			x=read();
			while(ans[x]==0)
			{
				printf("? %d\n",i);
				fflush(stdout);
				sth=read();
				fflush(stdout);
				ans[x]=sth;
				x=sth;
			}
		}
		printf("! ");
		for(int i=1;i<=n;i++)
		{
			printf("%d ",ans[i]);
		}
		printf("\n");
		fflush(stdout);
	}
	return 0;
}