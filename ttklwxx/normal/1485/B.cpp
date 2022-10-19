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
int a[200005];
int main()
{
	int n,q,k,l,r;
	n=read();
	q=read();
	k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=q;i++)
	{
		l=read();
		r=read();
		printf("%d\n",k+a[r]-a[l]-1-2*(r-l));
	}
	return 0;
}