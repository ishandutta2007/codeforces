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
int a[200001],qz[200001],qmax[200001];
int main()
{
	int t,n,k,z,ans,tans;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read()+1;
		z=read();
		ans=0;
		for(int i=1;i<=n;i++)a[i]=read(),qz[i]=qz[i-1]+a[i];
		qmax[1]=a[1]+a[2];
		for(int i=2;i<=n;i++)qmax[i]=max(qmax[i-1],a[i]+a[i+1]);
		tans=0;
		for(int j=0;j<=z;j++)
		{
			if(k<2*j)break;
			ans=max(ans,qz[k-2*j]+j*qmax[k-2*j]);
		}
		printf("%d\n",ans);
	}
	return 0;
}