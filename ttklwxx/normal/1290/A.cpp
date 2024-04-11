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
int a[100001];
int main()
{
    int t,n,m,k,ans=1000000000,nans;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		m=read();
		k=read();
		for(int j=1;j<=n;j++)a[j]=read();
		if(k>m-1)k=m-1;
		ans=0;
		for(int j=0;j<=k;j++)
		{
			nans=1000000000;
			for(int x=j;x<=m-1-(k-j);x++)
			{
				nans=min(nans,max(a[x+1],a[n-(m-1-x)]));
			}
			ans=max(ans,nans);
		}
		printf("%d\n",ans);
	} 
    return 0;
}