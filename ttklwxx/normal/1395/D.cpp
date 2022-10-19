#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a[200001],an,b[200001],bn;
bool bi(int x,int y)
{
	return x>y;
}
signed main()
{
	int n,d,m,x;
	n=read();
	d=read();
	m=read();
	for(int i=1;i<=n;i++)
	{
		x=read();
		if(x<=m)a[++an]=x;
		else b[++bn]=x;
	}
	sort(a+1,a+an+1,bi);
	sort(b+1,b+bn+1,bi);
	int ans=0;
	for(int i=2;i<=an;i++)a[i]+=a[i-1];
	for(int i=2;i<=bn;i++)b[i]+=b[i-1];
	ans=a[an];
	for(int i=1;i<=bn;i++)
	{
		if((i-1)*(d+1)+1>n)break;
		ans=max(ans,b[i]+a[min(n-(i-1)*(d+1)-1,an)]);
	}
	printf("%lld\n",ans);
	return 0;
}