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
int x[200001],y[200001],a[200001],b[200001];
int main()
{
    int n;
	n=read();
	if(n%2==1)
	{
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		x[i]=read();
		y[i]=read();
	}
	a[1]=x[1]-x[n];
	b[1]=y[1]-y[n];
	for(int i=2;i<=n;i++)a[i]=x[i]-x[i-1],b[i]=y[i]-y[i-1];
	for(int i=1;i<=n/2;i++)
	{
		if(a[i]!=-a[i+n/2]||b[i]!=-b[i+n/2])
		{
			printf("NO\n");
			return 0;
		}
		
	}
	printf("YES\n");
	return 0;
}