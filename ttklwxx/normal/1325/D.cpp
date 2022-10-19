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
signed main()
{
	int n,m,x,y,z,sl;
	n=read();
	m=read();
	n=m-n;
	if(n<0||n%2!=0)
	{
		printf("-1\n");
		return 0;
	}
	n/=2;
	x=0;
	y=0;
	for(int i=62;i>=0;i--)
	{
		if(n&(1LL<<i))x+=(1LL<<i),y+=(1LL<<i);
	}
	if(x+y>m)
	{
		printf("-1\n");
		return 0;
	}
	z=m-x-y;
	if((x&z)==0)x=x|z,z=0;
	if((y&z)==0)y=y|z,z=0;
	sl=0;
	if(x!=0)sl++;
	if(y!=0)sl++;
	if(z!=0)sl++;
	printf("%lld\n",sl);
	if(x!=0)printf("%lld ",x);
	if(y!=0)printf("%lld ",y);
	if(z!=0)printf("%lld ",z);
}