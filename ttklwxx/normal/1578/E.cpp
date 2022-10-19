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
	int t,n,h,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		h=read();
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		if(h<=a[n])
		{
			printf("1\n");
			continue;
		}
		k=(h-1)/(a[n]+a[n-1]);
		if(h-k*(a[n]+a[n-1])<=a[n])printf("%d\n",2*k+1);
		else printf("%d\n",2*k+2);
	} 
	return 0;
}