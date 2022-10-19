#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
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
int rd[200001];
struct bbian
{
	int u,v,nex,bh;
}a[800004];
int head[200001],tmp;
int t[200001];
void addb(int x,int y,int z)
{
	a[++tmp].u=x;
	a[tmp].v=y;
	a[tmp].bh=z;
	a[tmp].nex=head[x];
	head[x]=tmp;
}
int main()
{
	int n,x,y;
	n=read();
	for(int i=1;i<=n-1;i++)
	{
		x=read();
		y=read();
		addb(x,y,i);
		addb(y,x,i);
		rd[x]++;
		rd[y]++;
	}
	for(int tx=1;tx<=n;tx++)
	{
		if(rd[tx]>=3)
		{
			x=0;
			for(int i=head[tx];x<=2;i=a[i].nex)
			{
				t[a[i].bh]=x+1;
				x++;
			}
			for(int i=1;i<=n-1;i++)
			{
				if(t[i])printf("%d\n",t[i]-1);
				else printf("%d\n",x),x++; 
			}
			return 0;
		}
	}
	for(int i=1;i<=n-1;i++)printf("%d\n",i-1);
	return 0;
}