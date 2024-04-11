#include<iostream>
#include<cstdio>
using namespace std;
int read()
{
	int n=0,f=1,ch=getchar();
	while(ch==' '||ch=='\n')ch=getchar();
	if(ch=='-')
	{
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int fa[500000];
int findf(int n)
{
	if(fa[n]==n)return n;
	return fa[n]=findf(fa[n]);
}
int main()
{
	int n,m,q,ans,x,y;
	n=read();
	m=read();
	q=read();
	for(int i=1;i<=n+m;i++)fa[i]=i;
	ans=n+m;
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		y+=n;
		x=findf(x);
		y=findf(y);
		if(x!=y)
		{
			fa[x]=y;
			ans--;
		}
	}
	cout<<ans-1<<endl;
	return 0;
}