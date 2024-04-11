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
int a[100001];
int sl[31];
bool bi(int x,int y)
{
	return x>y;
}
int main()
{
    int n,ans=-1,nans=0,pans;
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
    	for(int j=0;j<=30;j++)
    	{
    		if(a[i]&(1<<j))sl[j]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		nans=0;
		for(int j=0;j<=30;j++)
		{
			if((a[i]&(1<<j))==0)continue;
			if(sl[j]>1)continue;
			nans|=(1<<j);
		}
		if(nans>ans)
		{
			ans=nans;
			pans=i;
		}
	}
	printf("%d ",a[pans]);
	for(int i=1;i<=n;i++)
	{
		if(i==pans)continue;
		printf("%d ",a[i]);
	}
    return 0;
}