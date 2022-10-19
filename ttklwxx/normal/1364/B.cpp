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
int n,x;
int a[200001];
int main()
{
	int t,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ans=2;
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])ans++;
			if(a[i]<a[i-1]&&a[i]<a[i+1])ans++;
		}
		printf("%d\n",ans);
		printf("%d ",a[1]);
		for(int i=2;i<=n-1;i++)
		{
			if(a[i]>a[i-1]&&a[i]>a[i+1])printf("%d ",a[i]); 
			if(a[i]<a[i-1]&&a[i]<a[i+1])printf("%d ",a[i]);
		}
		printf("%d\n",a[n]);
	} 
	return 0;
}