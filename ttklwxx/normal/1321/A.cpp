#include<iostream>
#include<cstdio>
using namespace std;
int a[1001],b[1001];
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
int main()
{
	int n,sl1=0,sl2=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(a[i]==1&&b[i]==0)sl1++;
		if(a[i]==0&&b[i]==1)sl2++;
	}
	if(sl1!=0)printf("%d\n",sl2/sl1+1);
	else printf("-1\n");
	return 0;
}