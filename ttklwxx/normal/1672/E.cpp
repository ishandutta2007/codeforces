#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
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
int main()
{
	int t,n,sl,l,r,mid,ans,tans=1000000000;
	n=read();
	l=2*n-1;
	r=2000*n+n-1;
	while(l<=r)
	{
		mid=(l+r)>>1;
		printf("? %d\n",mid);
		fflush(stdout);
		ans=read();
		if(ans==1)r=mid-1;
		else l=mid+1;
	}
	int sth=l+1;
	tans=l;
	for(int i=2;i<=n;i++)
	{
		printf("? %d\n",(sth-1)/i);
		fflush(stdout);
		ans=read();
		if(ans==i)tans=min(tans,i*((sth-1)/i));
	}
	printf("! %d\n",tans);
	fflush(stdout);
	return 0;
}