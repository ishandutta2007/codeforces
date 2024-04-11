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
int b[200005],cnt;
signed main()
{
	int n,k,x,ans=1;
	n=read();
	k=read();
	x=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++)
	{
		if(a[i+1]-a[i]<=x)continue;
		ans++;
		b[++cnt]=(a[i+1]-a[i]-1)/x;
	}
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;i++)
	{
		if(k<b[i])break;
		k-=b[i];
		ans--;
	}
	printf("%lld\n",ans);
	return 0;
}