#include<iostream>
#include<cstdio>
#define int long long
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
int a[400005];
int gcd(int x,int y)
{
	if(x==0)return y;
	if(y==0)return x;
	if(x<0)x=-x;
	if(y<0)y=-y;
	while(x^=y^=x^=y%=x);
	return y;
}
signed main()
{
	int t,n,k,sth;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=2;i<=n;i++)a[i]=a[i]-a[1];
		sth=a[2];
		if(sth<0)sth=-sth;
		for(int i=3;i<=n;i++)sth=gcd(sth,a[i]);
		if((k%sth+sth)%sth==(a[1]%sth+sth)%sth)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}