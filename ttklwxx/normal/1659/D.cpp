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
int p[200005];
int f[200005],n;
int cf[200005];
int zh[200005];
signed main()
{
	int t,a,b,now,minn,het;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		het=0;
		for(int i=1;i<=n;i++)p[i]=read(),cf[i]=0,het+=p[i];
		now=0;
		for(int i=n;i>=1;i--)
		{
			zh[i]=het/i;
			//printf("orz%lld %lld\n",i,zh[i]);
			now+=cf[i];
			p[i]-=now;
			if(zh[i]!=0)
			{
				now++;
				p[i]--;
				cf[i-zh[i]]--;
				het-=zh[i];
			}
			het-=p[i];
		}
		for(int i=1;i<=n;i++)printf("%d ",zh[i]-zh[i-1]);
		printf("\n");
	}
}