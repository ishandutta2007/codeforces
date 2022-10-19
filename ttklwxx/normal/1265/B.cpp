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
int pos[1000001];
int main()
{
	int t,l,r,n,x;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		for(int j=1;j<=n;j++)
		{
			x=read();
			pos[x]=j;
		}
		l=1000000000;
		r=0;
		for(int j=1;j<=n;j++)
		{
			l=min(pos[j],l);
			r=max(pos[j],r);
			if(r-l+1==j)
			{
				printf("1");
			}
			else printf("0");
		}
		printf("\n");
	}
}