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
int a[105];
int main()
{
	int t,n,r,b,maxn,sl=0,sl0,now;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		r=read();
		b=read();
		maxn=(r-1)/(b+1)+1;
		sl=r;
		sl0=0;
		for(int i=1;i<=b+1;i++)
		{
			a[i]=min(sl,maxn);
			sl-=a[i];
			if(a[i]==0)sl0++;
		}
		now=0;
		sl=1;
		while(sl<=b+1&&a[sl]!=0)
		{
			while(sl0>0&&now<maxn)
			{
				now++;
				printf("B");
				sl0--;
			}
			for(int i=1;i<=a[sl];i++)printf("R");
			sl++;
			if(sl<=b+1&&a[sl]!=0)printf("B");
			now=1;
		}
		printf("\n");
	}
}