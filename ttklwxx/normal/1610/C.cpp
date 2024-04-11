//Chapter III: The Grand Illusion 
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
int a[200005],b[200005];
bool check(int n,int k)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]+min(ans,b[i])<k-1)continue;
		ans=max(ans,min(ans,b[i])+1);
	}
	if(ans>=k)return true;
	else return false;
}
int main()
{
	int t,n,l,r,mid;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			a[i]=read();
			b[i]=read();
		}
		l=1;
		r=n;
		while(l<=r)
		{
			mid=(l+r)>>1;
			if(check(n,mid))l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}