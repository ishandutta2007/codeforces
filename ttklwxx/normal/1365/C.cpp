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
int a[500001],b[500001],ans[500001];
int main()
{
	int n,tans=0;
	n=read();
	for(int i=1;i<=n;i++)a[read()]=i;
	for(int i=1;i<=n;i++)b[read()]=i;
	for(int i=1;i<=n;i++)ans[(b[i]-a[i]+n)%n]++;
	for(int i=0;i<=n-1;i++)tans=max(tans,ans[i]);
	printf("%d\n",tans);
	return 0;
}