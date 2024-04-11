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
bool cx[1001];
int que[1001],a[1001],top;
int main()
{
	int t,n,k,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		sth=0;
		top=0;
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)
		{
			if(cx[a[i]]==0)
			{
				cx[a[i]]=1;
				sth++;
				que[++top]=a[i];
			}
		}
		if(sth>k)
		{
			printf("-1\n");
			for(int i=1;i<=n;i++)cx[i]=0;
			continue;
		}
		printf("%d\n",n*k);
		for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)if(j<=top)printf("%d ",que[j]);else printf("%d ",a[1]);
		printf("\n");
	    for(int i=1;i<=n;i++)cx[i]=0;
	}
	return 0;
}