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
int a[200005],qz[200005];
int main()
{
	int n,k;
	bool flag;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)a[i]=read();
	int l=1,r=n,mid,sth;
	while(l<=r)
	{
		mid=(l+r)>>1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=mid)qz[i]=qz[i-1]+1;
			else qz[i]=qz[i-1]-1;
		}
		flag=false;
		sth=0;
		for(int i=0;i<=n-k;i++)
		{
			sth=min(sth,qz[i]);
			if(qz[i+k]>sth)
			{
				flag=true;
				break;
			}
		}
		if(flag==true)l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",r);
	return 0;
}