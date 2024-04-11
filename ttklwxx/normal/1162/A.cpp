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
int maxn[100001];
int main()
{
	int n,h,m,x,y,z,ans=0;
	n=read();
	h=read();
	m=read();
	for(int i=1;i<=n;i++)maxn[i]=h;
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		z=read();
		for(int j=x;j<=y;j++)maxn[j]=min(maxn[j],z);
	} 
	for(int i=1;i<=n;i++)ans+=maxn[i]*maxn[i];
	printf("%d\n",ans);
	return 0;
	return 0;
}