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
bool cza[1001],czb[1001];
int main()
{
	int t,n,m,x,y;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		m=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				x=read();
				if(x==1)cza[i]=1,czb[j]=1;
			}
		}
		x=0;
		y=0;
		for(int i=1;i<=n;i++)if(cza[i]==0)x++;
		for(int i=1;i<=m;i++)if(czb[i]==0)y++;
		for(int i=1;i<=n;i++)cza[i]=0;
		for(int i=1;i<=m;i++)czb[i]=0;
		if(min(x,y)%2==0)printf("Vivek\n");
		else printf("Ashish\n");
	} 
	return 0;
}