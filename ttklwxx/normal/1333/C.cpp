#include<iostream>
#include<cstdio>
#include<map>
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
int qz[200005],xy[200005];
map<int,int>ma;
signed main()
{
	int n;
	n=read();
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+read();
	for(int i=n;i>=0;i--)
	{
		xy[i]=ma[qz[i]];
		if(xy[i]==0)xy[i]=n+1;
		ma[qz[i]]=i;
	}
	for(int i=n-1;i>=0;i--)xy[i]=min(xy[i],xy[i+1]);
	int ans=0;
	for(int i=0;i<=n-1;i++)ans+=xy[i]-i-1;
	printf("%lld\n",ans);
	return 0;
}