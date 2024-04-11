#include<iostream>
#include<cstdio>
#include<cmath>
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
map<int,int>ma;
int a[200001];
int main()
{
	int t,n,ans=0;
	t=read();
	for(int i=1;i<=t;i++)
	{
		ans=0;
		n=read();
		for(int j=1;j<=n;j++)a[j]=read();
		for(int j=1;j<=n;j++)
		{
			if(!ma[a[j]])
			{
				ans++;
				ma[a[j]]=1;
			}
		}
		printf("%d\n",ans);
		for(int j=1;j<=n;j++)ma[a[j]]=0;
	}
	return 0;
}