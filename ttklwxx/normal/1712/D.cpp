#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#define mod 998244353
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
int a[100005],las[100005],fir[100005];
int b[100005];
int main()
{
	int t,n,k,l,r,mid,nsl,minn;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)a[i]=read();
		l=1;
		r=1000000000;
		while(l<=r)
		{
			mid=(l+r)>>1;
			for(int i=1;i<=n;i++)b[i]=a[i];
			nsl=0;
			for(int i=1;i<=n;i++)
			{
				if(b[i]*2<mid)
				{
					b[i]=1000000000;
					nsl++;
				}
			}
			minn=1000000000;
			for(int i=1;i<=n-1;i++)
			{
				int now=0;
				if(b[i]<mid)now++;
				if(b[i+1]<mid)now++;
				minn=min(minn,now); 
			}
			nsl+=minn;
			if(nsl<=k)l=mid+1;
			else r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}