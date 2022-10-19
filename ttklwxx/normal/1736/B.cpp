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
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
int a[100005],b[100005];
int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
int main()
{
	int t,n,sl1,sl2,now,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		b[1]=a[1];
		b[n+1]=a[n];
		for(int i=2;i<=n;i++)
		{
			b[i]=a[i-1]/gcd(a[i-1],a[i])*a[i];
		}
		bool flag=true;
		for(int i=1;i<=n;i++)if(gcd(b[i],b[i+1])!=a[i])
		{
			flag=false;
			break;
		}
		if(flag==true)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}