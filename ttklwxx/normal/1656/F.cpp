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
int a[200005];
int qz[200005];
signed main()
{
	int t,n,sth1,sth2;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		qz[0]=0;
		for(int i=1;i<=n;i++)a[i]=read();
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i];
		sth1=0;
		for(int i=1;i<=n;i++)sth1+=a[i];
		sth2=sth1;
		sth1+=(n-2)*a[1];
		sth2+=(n-2)*a[n];
		if(sth1>0||sth2<0)
		{
			printf("INF\n");
			continue;
		}
		int ans=-1000000000000000000LL;
		for(int ch=n;ch>=1;ch--)
		{
			ans=max(ans,(a[n]-a[ch])*(qz[ch]-ch*a[ch])+(a[1]-a[ch])*(qz[n]-qz[ch]-(n-ch)*a[ch])-(a[1]-a[ch])*(a[n]-a[ch])-(n-1)*a[ch]*a[ch]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}