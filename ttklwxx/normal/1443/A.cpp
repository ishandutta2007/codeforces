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
int t,n;
bool vis[1001];
int pri[1001],cnt;
int main()
{
	int t,n;
	t=read();
	for(int i=2;i<=1000;i++)
	{
		if(!vis[i])
		{
			pri[++cnt]=i;
		}
		for(int j=1;j<=cnt&&i*pri[j]<=1000;j++)
		{
			vis[i*pri[j]]=true;
			if(i%pri[j]==0)break;
		}
	}
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=n+1;i<=2*n;i++)printf("%d ",2*i);
		printf("\n"); 
	}
	return 0;
}