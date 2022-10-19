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
int fa[1005],siz[1005];
int pos[1005];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]); 
}
bool bi(int x,int y)
{
	return siz[x]<siz[y];
}
signed main()
{
	int n,d,ans=0,x,y,sl=0;
	n=read();
	d=read();
	for(int i=1;i<=n;i++)fa[i]=i,siz[i]=1;
	for(int i=1;i<=d;i++)
	{
		x=read();
		y=read();
		x=findf(x);
		y=findf(y);
		if(x!=y)
		{
			fa[x]=y;
			siz[y]+=siz[x];
			siz[x]=0;
		}
		else
		{
			sl++;
		}
		for(int j=1;j<=n;j++)
		{
			pos[j]=j;
		}
		sort(pos+1,pos+n+1,bi);
		ans=0;
		for(int j=n;j>=n-sl;j--)ans+=siz[pos[j]];
		printf("%d\n",ans-1);
	}
	return 0;
}