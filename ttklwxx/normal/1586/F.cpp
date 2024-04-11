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
int main()
{
	int n,k,ans=0,sz=1;
	n=read();
	k=read();
	while(sz<n)
	{
		sz*=k;
		ans++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			sz=1;
			ans=0;
			while((i-1)/sz!=(j-1)/sz)
			{
				sz*=k;
				ans++;
			}
			printf("%d ",ans);
		}
	}
	return 0;
}