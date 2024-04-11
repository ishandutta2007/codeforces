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
int sl[1000005];
signed main()
{
	int t,n,w,x,ans,sth,gre;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		w=read();
		for(int i=1;i<=n;i++)
		{
			x=read();
			sl[x]++;
		}
		ans=0;
		sth=n;
		while(sth!=0)
		{
			ans++;
			gre=w;
			for(int j=(1<<19);j>=1;j/=2)
			{
				if(gre>sl[j]*j)
				{
					gre-=sl[j]*j;
					sth-=sl[j];
					sl[j]=0;
				}
				else
				{
					sth-=gre/j;
					sl[j]-=gre/j;
					gre-=(gre/j)*j;
				}
			}
		}
		printf("%lld\n",ans);
	} 
	return 0;
}