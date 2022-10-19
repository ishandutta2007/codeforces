#include<iostream>
#include<cstdio>
#include<algorithm>
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
int pos[200005],a[200005];
bool bi(int x,int y)
{
	return a[x]<a[y];
}
int ans[200005];
signed main()
{
	int t,n,minn,zh;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			pos[i]=i;
			a[i]=read();
		}
		sort(pos+1,pos+n+1,bi);
		zh=0;
		minn=0;
		for(int i=1;i<=n;i++)
		{
			if(a[pos[i]]>zh)minn=i;
			zh+=a[pos[i]];
		}
		for(int i=1;i<=n-minn+1;i++)ans[i]=pos[i+minn-1];
		sort(ans+1,ans+n-minn+2);
		printf("%d\n",n-minn+1);
		for(int i=1;i<=n-minn+1;i++)printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}