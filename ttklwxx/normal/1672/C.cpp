#include<iostream>
#include<cstdio>
#include<cstring>
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
	int t,n,sl,l,r;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sl=0;
		for(int i=1;i<=n-1;i++)if(a[i]==a[i+1])sl++;
		if(sl<=1)
		{
			printf("0\n");
			continue;
		}
		l=1;
		while(l<=n&&a[l]!=a[l+1])l++;
		r=n;
		while(r>=1&&a[r]!=a[r-1])r--;
		printf("%d\n",max(1,r-l-2));
	} 
	return 0;
}