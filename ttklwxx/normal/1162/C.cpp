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
int a[200001],lcx[200001],rcx[200001];
int main()
{
	int n,k,ans=0;
	bool flag;
	n=read();
	k=read();
	for(int i=1;i<=k;i++)a[i]=read();
	for(int i=1;i<=k;i++)rcx[a[i]]=i;
	for(int i=k;i>=1;i--)lcx[a[i]]=i;
	for(int i=1;i<=n;i++)if(lcx[i]==0)ans++;
	for(int i=1;i<=n-1;i++)
	{
		if(lcx[i]==0||lcx[i]>rcx[i+1])ans++;
	}
	for(int i=2;i<=n;i++)
	{
		if(lcx[i]==0||lcx[i]>rcx[i-1])ans++;
	}
	printf("%d\n",ans);
	return 0;
}