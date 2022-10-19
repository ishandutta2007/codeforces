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
int a[205];
bool vis[20005];
int pri[20005],cnt;
int main()
{
	int t,n,su=0;
	t=read();
	for(int i=2;i<=20000;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=20000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		su=0;
		for(int i=1;i<=n;i++)a[i]=read(),su+=a[i];
		if(vis[su])
		{
			printf("%d\n",n);
			for(int i=1;i<=n;i++)printf("%d ",i);
			printf("\n");
			continue;
		}
		for(int i=1;i<=n;i++)if(vis[su-a[i]])
		{
			printf("%d\n",n-1);
			for(int j=1;j<=n;j++)if(j!=i)printf("%d ",j);
			printf("\n");
			break;
		}
	}
	return 0;
}