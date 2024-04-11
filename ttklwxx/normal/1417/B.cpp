#include<iostream>
#include<cstdio>
#include<map>
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
int a[200001],zs[200001];
map<int,int>ma;
int main()
{
	int t,n,sl,ans=0,tsl=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		sl=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ma.clear();
		tsl=1;
		for(int i=1;i<=n;i++)
		{
			if(sl%2==0&&a[i]==sl/2)
			{
				zs[i]=tsl;
				tsl=3-tsl;
				continue;
			}
			if(ma[a[i]]!=0)zs[i]=ma[a[i]];
			else if(ma[sl-a[i]]!=0)zs[i]=3-ma[sl-a[i]];
			else zs[i]=1;
			ma[a[i]]=zs[i];
		}
		for(int i=1;i<=n;i++)printf("%d ",zs[i]-1);
		printf("\n");
	}
	return 0;
}