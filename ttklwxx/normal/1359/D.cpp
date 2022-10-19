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
int maxl[100005][70],maxr[100005][70],a[100005];
int main()
{
	int n,ans=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=0;i<=60;i++)
	{
		maxl[i][0]=0;
		for(int j=1;j<=n;j++)
		{
			if(a[j]<=i-30)maxl[j][i]=max(maxl[j-1][i]+a[j],a[j]);
			else maxl[j][i]=0;
		}
		maxr[n+1][0]=0;
		for(int j=n;j>=1;j--)
		{
			if(a[j]<=i-30)maxr[j][i]=max(maxr[j+1][i]+a[j],a[j]);
			else maxr[j][i]=0;
		}
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,max(0,maxl[i-1][a[i]+30])+max(0,maxr[i+1][a[i]+30]));
	}
	printf("%d\n",ans);
	return 0;
}