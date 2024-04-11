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
int pri[100005],cnt,nex[100005];
bool vis[100005];
int main()
{
	for(int i=2;i<=100000;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=100000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	for(int i=100000;i>=2;i--)
	{
		if(vis[i]==false)nex[i]=i;
		else nex[i]=nex[i+1];
	}
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		if(n==1)
		{
			printf("6\n");
			continue;
		}
		printf("%lld\n",1LL*nex[n+1]*nex[nex[n+1]+n]);
	} 
	return 0;
}