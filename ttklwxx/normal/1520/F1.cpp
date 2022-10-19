#include<iostream>
#include<cstdio>
#include<cstring>
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
	int n,t,ans,k;
	n=read();
	t=read();
	k=read();
	int l=1,r=n,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		printf("? %d %d\n",1,mid);
		fflush(stdout);
		ans=read();
		ans=mid-ans;
		if(ans<k)l=mid+1;
		else r=mid-1;
	}
	printf("! %d\n",l);
	return 0;
}