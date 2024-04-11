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
int a[200005],b[200005];
int jdz(int x)
{
	if(x<0)return -x;
	return x;
}
signed main()
{
	int t,n,minna1,minnan,minnb1,minnbn,ans;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1;i<=n;i++)b[i]=read();
		minna1=1000000000;
		minnb1=minnbn=minnan=minna1;
		for(int i=1;i<=n;i++)
		{
			minna1=min(minna1,jdz(a[1]-b[i]));
			minnan=min(minnan,jdz(a[n]-b[i]));
			minnb1=min(minnb1,jdz(b[1]-a[i]));
			minnbn=min(minnbn,jdz(b[n]-a[i]));
		}
		ans=1121131433448687LL;
		ans=min(ans,minna1+minnan+minnb1+minnbn);
		ans=min(ans,jdz(a[1]-b[1])+minnan+minnbn);
		ans=min(ans,jdz(a[n]-b[1])+minna1+minnbn);
		ans=min(ans,jdz(a[1]-b[n])+minnan+minnb1);
		ans=min(ans,jdz(a[n]-b[n])+minna1+minnb1);
		ans=min(ans,jdz(a[1]-b[1])+jdz(a[n]-b[n]));
		ans=min(ans,jdz(a[1]-b[n])+jdz(a[n]-b[1]));
		printf("%lld\n",ans);
	}
	return 0;
}