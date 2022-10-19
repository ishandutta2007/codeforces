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
int a[1005],b[1005];
int main()
{
	int t,n,sl1,sl2,now,ans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		now=0;
		for(int i=1;i<=n;i++)now+=(a[i]^b[i]);
		ans=now;
		sl1=sl2=0;
		for(int i=1;i<=n;i++)sl1+=a[i];
		for(int i=1;i<=n;i++)sl2+=b[i];
		ans=min(ans,jdz(sl1-sl2)+1);
		printf("%d\n",ans);
	}
	return 0;
}