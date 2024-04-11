#include<iostream>
#include<cstdio>
#include<algorithm>
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
int h[200005],nh[200005];
int n;
bool check(int k)
{
	for(int i=1;i<=n;i++)nh[i]=h[i];
	int x=0;
	for(int i=n;i>=3;i--)
	{
		x=max(min((nh[i]-k)/3,h[i]/3),0);
		nh[i]-=x*3;
		nh[i-1]+=x;
		nh[i-2]+=x*2;
	}
	//for(int i=1;i<=n;i++)printf("")
	for(int i=1;i<=n;i++)if(nh[i]<k)return false;
	//printf("vis:%d\n",k);
	return true;
}
int main()
{
	int t,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)h[i]=read();
		l=1;
		r=1000000000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(mid))l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	} 
	return 0;
}