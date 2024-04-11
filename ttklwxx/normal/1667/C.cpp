#include<iostream>
#include<cstdio>
#include<cmath>
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
void findgz(int n)
{
	if(n==1)
	{
		printf("%d %d\n",1,1);
		return;
	}
	if(n==2)
	{
		printf("%d %d\n",1,1);
		return;
	}
	if(n==3)
	{
		printf("%d %d\n",1,1);
		printf("%d %d\n",1,2);
		return;
	}
	int ans=(2*n+1)/3,maxn=n-ans;
	for(int i=1;i<=maxn;i++)
	{
		printf("%d %d\n",i,maxn+1-i);
	}
	for(int i=1;i<=(maxn-1);i++)
	{
		printf("%d %d\n",maxn+i,maxn+maxn-i);
	}
	for(int i=2*maxn;i<=ans;i++)printf("%d %d\n",i,i);
}
signed main()
{
	int n,ans;
	n=read();
	ans=(2*n+1)/3;
	printf("%d\n",ans);
	findgz(n);
	return 0;
}