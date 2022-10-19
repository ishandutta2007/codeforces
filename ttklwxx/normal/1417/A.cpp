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
int a[1005];
int main()
{
	int t,n,k,mpos,ans;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		k=read();
		a[0]=1000000000;
		mpos=0;
		ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			if(a[i]<a[mpos])mpos=i;
		}
		for(int i=1;i<=n;i++)
		{
			if(i==mpos)continue;
			ans+=(k-a[i])/a[mpos];
		}
		printf("%d\n",ans);
	} 
	return 0;
}