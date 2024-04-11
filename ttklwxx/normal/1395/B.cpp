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
int ax[100001],ay[100001],tmp;
int main()
{
	int n,m,x,y;
	n=read();
	m=read();
	x=read();
	y=read();
	ax[++tmp]=x;
	ay[tmp]=y;
	for(int j=1;j<=m;j++)
	{
		if(j==y)continue;
		ax[++tmp]=x;
		ay[tmp]=j;
	}
	int ks=m;
	for(int i=1;i<=n;i++)
	{
		if(i==x)continue;
		if(ks==m)
		{
			for(int j=m;j>=1;j--)
			{
				ax[++tmp]=i;
				ay[tmp]=j;
			}
			ks=1;
		}
		else
		{
			for(int j=1;j<=m;j++)
			{
				ax[++tmp]=i;
				ay[tmp]=j;
			}
			ks=m;
		}
	}
	for(int i=1;i<=tmp;i++)printf("%d %d\n",ax[i],ay[i]);
	return 0;
}