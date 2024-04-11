#include<iostream>
#include<cstdio>
#define int long long
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
bool cz[200005];
int fa[31][100005],fc[31][100005];
int findf(int k,int n)
{
	if(fa[k][n]==n)return n;
	return fa[k][n]=findf(k,fa[k][n]);
}
int bu[100005],bv[100005],bw[100005];
signed main()
{
	int n,m,x,y,z;
	n=read();
	m=read();
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		z=read();
		if(z%2==0)cz[x]=cz[y]=true;
		bu[i]=x;
		bv[i]=y;
		bw[i]=z;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=30;j++)
		{
			if(j>0&&cz[i]==true)fc[j][i]=true;
			fa[j][i]=i;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=30;j++)
		{
			if((bw[i]&(1<<j))==0)continue;
			x=findf(j,bu[i]);
			y=findf(j,bv[i]);
			if(x==y)continue;
			fa[j][x]=y;
			if(fc[j][x]==true)
			{
				fc[j][y]=true;
			}
		}
	}
	bool flag=false;
	int q=read();
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		flag=false;
		for(int j=0;j<=30;j++)
		{
			if(findf(j,x)==findf(j,y))
			{
				flag=true;
				break;
			}
		}
		if(flag==true)
		{
			printf("0\n");
			continue;
		}
		for(int j=1;j<=30;j++)
		{
			if(fc[j][findf(j,x)]==true)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)
		{
			printf("1\n");
			continue;
		}
		printf("2\n");
	}
}