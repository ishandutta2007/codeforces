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
int a[200005],b[32];
int gcd(int x,int y)
{
	if(x==0)return y;
	if(y==0)return x;
	while(x^=y^=x^=y%=x);
	return y;
}
int main()
{
	int t,n,ans=0;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=0;i<30;i++)b[i]=0;
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			for(int j=0;j<30;j++)if(a[i]&(1<<j))b[j]++;
		}
		ans=0;
		for(int i=0;i<30;i++)ans=gcd(ans,b[i]);
		//printf("%d\n",ans);
		for(int i=1;i<=n;i++)if(ans%i==0)printf("%d ",i);
		printf("\n");
	}
}