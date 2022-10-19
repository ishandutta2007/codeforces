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
int ans[1000001][2];
bool vis[10000001],cm[10000001];
int pri[10000001],cnt,zc[10000001];
int main()
{
	int t,n,x=0;
	t=read();
	for(int i=2;i<=10000000;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
			zc[i]=i;
			cm[i]=true;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=10000000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]!=0)
			{
				cm[i*pri[j]]=false;
				zc[i*pri[j]]=pri[j];
			}
			else
			{
				cm[i*pri[j]]=cm[i];
				zc[i*pri[j]]=zc[i]*pri[j];
			}
		}
	}
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(cm[n]==true)
		{
			ans[greg][0]=ans[greg][1]=-1;
			continue;
		}
		ans[greg][0]=zc[n];
		ans[greg][1]=n/zc[n];
	}
	for(int i=1;i<=t;i++)printf("%d ",ans[i][0]);
	printf("\n");
	for(int i=1;i<=t;i++)printf("%d ",ans[i][1]);
	printf("\n");
	return 0;
}