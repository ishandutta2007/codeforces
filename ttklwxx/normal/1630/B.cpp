#include<iostream>
#include<cstdio>
#include<cstdlib>
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
int a[300005],sl[300005];
int main()
{
	int t,n,k,l,maxn,maxp,gre,sth,las;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		for(int i=1;i<=n;i++)sl[i]=0;
		for(int i=1;i<=n;i++)a[i]=read(),sl[a[i]]++;
		for(int i=2;i<=n;i++)sl[i]+=sl[i-1];
		l=1;
		maxn=1000000000;
		maxp=0;
		for(int i=1;i<=n;i++)
		{
			while(l<=i&&sl[i]-sl[l]>=(n+k+1)/2)l++;
			if(sl[i]-sl[l-1]<(n+k+1)/2)continue;
			if(i-l+1<maxn)
			{
				maxn=i-l+1;
				maxp=i;
			}
		}
		printf("%d %d\n",maxp-maxn+1,maxp);
		gre=1;
		sth=0;
		las=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>=maxp-maxn+1&&a[i]<=maxp)sth++;
			else sth--;
			if(gre<=k-1&&sth==gre)printf("%d %d\n",las+1,i),gre++,las=i;
		}
		printf("%d %d\n",las+1,n);
	}
	return 0;
}