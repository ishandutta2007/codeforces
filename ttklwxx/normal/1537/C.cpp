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
int h[200005];
int main()
{
	int t,n,minn,mpos;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)h[i]=read();
		sort(h+1,h+n+1);
		if(n==2)
		{
			printf("%d %d\n",h[1],h[2]);
			continue;
		}
		minn=1000000000;
		mpos=0;
		for(int i=1;i<=n-1;i++)
		{
			if(h[i+1]-h[i]<minn)
			{
				minn=h[i+1]-h[i];
				mpos=i;
			}
		}
		for(int i=mpos+1;i<=n;i++)printf("%d ",h[i]);
		for(int i=1;i<=mpos;i++)printf("%d ",h[i]);
		printf("\n");
	}
	return 0;
}