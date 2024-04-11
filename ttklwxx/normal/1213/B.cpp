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
int a[300001];
int main()
{
	int t,n,minn,ans=0;
	t=read();
	for(int sth=1;sth<=t;sth++)
	{
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	minn=a[n];
	ans=0;
	for(int i=n-1;i>=1;i--)
	{
		if(a[i]>minn)ans++;
		minn=min(minn,a[i]);
	}
	printf("%d\n",ans);
    }
	return 0;
}