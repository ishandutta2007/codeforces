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
int a[300005],pre[300005],kam[300005],tans[300005];
int main()
{
	int t,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)pre[i]=0,kam[i]=0,tans[i]=1000000000;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			kam[a[i]]=max(kam[a[i]],i-pre[a[i]]);
			pre[a[i]]=i;
		}
		for(int i=1;i<=n;i++)kam[a[i]]=max(kam[a[i]],n+1-pre[a[i]]);
		for(int i=1;i<=n;i++)tans[kam[a[i]]]=min(tans[kam[a[i]]],a[i]);
		for(int i=2;i<=n;i++)tans[i]=min(tans[i],tans[i-1]);
		for(int i=1;i<=n;i++)
		{
			if(tans[i]!=1000000000)printf("%d ",tans[i]);
			else printf("-1 ");
		}
		printf("\n");
	}
	return 0;
}