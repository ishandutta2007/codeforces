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
int sl[200001],a[200001],ans[200001];
signed main()
{
	int n,x,k,minn=100000000;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		x=0;
		while(a[i]!=0)
		{
			if(sl[a[i]]!=k)
			{
				sl[a[i]]++;
				ans[a[i]]+=x;
			}
			x++;
			a[i]/=2;
		}
		sl[0]++;
		ans[0]+=x;
	}
	for(int i=0;i<=200000;i++)if(sl[i]==k)minn=min(minn,ans[i]);
	printf("%d\n",minn);
	return 0;
}