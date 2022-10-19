#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define int long long
using namespace std;
int cf[200001];
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
int xx[200005];
signed main()
{
	int n,m,x,y,ans;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)xx[i]=read();
	for(int i=1;i<=m-1;i++)
	{
		if(xx[i]==xx[i+1])continue;
		x=min(xx[i],xx[i+1]);
		y=max(xx[i],xx[i+1]);
		cf[1]+=abs(x-y);
		cf[x]+=abs(1-y)-abs(x-y);
		cf[x+1]+=abs(y-x-1)-abs(y-1);
		cf[y]+=abs(1-x-1)-abs(y-x-1);
		cf[y+1]+=abs(y-x)-abs(1-x-1);
	}
	ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=cf[i];
		printf("%I64d ",ans);
	}
	return 0;
}