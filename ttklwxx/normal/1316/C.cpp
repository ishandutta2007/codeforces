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
int a[2000001],b[2000001];
int main()
{
	int x=1,n,m,p,y=1;
	n=read();
	m=read();
	p=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int j=1;j<=m;j++)b[j]=read();
	while(a[x]%p==0)x++;
	while(b[y]%p==0)y++;
	printf("%d\n",x+y-2);
	return 0;
}