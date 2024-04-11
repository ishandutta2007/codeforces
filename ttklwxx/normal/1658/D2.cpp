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
int a[200005];
int main()
{
	int t,l,r,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		l=read();
		r=read();
		ans=0;
		for(int i=l;i<=r;i++)a[i]=read();
		for(int i=17;i>=0;i--)
		{
			sort(a+l,a+r+1);
			for(int j=l;j<=r;j++)
			{
				if(((a[j]>>i)&1)!=((j>>i)&1))
				{
					ans=ans|(1<<i);
					break;
				}
			}
			if(ans&(1<<i))
			{
				for(int j=l;j<=r;j++)
				{
					a[j]=a[j]^(1<<i);
				}
			}
		}
		printf("%d\n",ans);
	}
}