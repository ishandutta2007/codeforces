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
int fa1[100005],fa2[100005];
int findf1(int n)
{
	if(fa1[n]==n)return n;
	else return fa1[n]=findf1(fa1[n]);
}
int findf2(int n)
{
	if(fa2[n]==n)return n;
	else return fa2[n]=findf2(fa2[n]);
}
int ansx[200005],ansy[200005];
int main()
{
	int n,m1,m2,x,y,tx,ty;
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=n;i++)
	{
		fa1[i]=i;
		fa2[i]=i;
	}
	for(int i=1;i<=m1;i++)
	{
		x=read();
		y=read();
		x=findf1(x);
		y=findf1(y);
		fa1[x]=y;
	}
	for(int i=1;i<=m2;i++)
	{
		x=read();
		y=read();
		x=findf2(x);
		y=findf2(y);
		fa2[x]=y;
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			x=findf1(i);
			y=findf1(j);
			if(x==y)continue;
			tx=findf2(i);
			ty=findf2(j);
			if(tx==ty)continue;
			fa1[x]=y;
			fa2[tx]=ty;
			ans++;
			ansx[ans]=i;
			ansy[ans]=j;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=ans;i++)printf("%d %d\n",ansx[i],ansy[i]);
	return 0;
}