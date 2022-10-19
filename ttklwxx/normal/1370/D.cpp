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
int a[400001],n,k;
bool check(int mid)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt%2==1)
		{
			if(a[i]<=mid)cnt++;
		}
		else cnt++;
	}
	if(cnt>=k)return true;
	cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(cnt%2==0)
		{
			if(a[i]<=mid)cnt++;
		}
		else cnt++;
	}
	if(cnt>=k)return true;
	return false; 
}
int main()
{
	int l=1,r=0,mid;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)a[i]=read(),r=max(r,a[i]);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",l);
	return 0;
}